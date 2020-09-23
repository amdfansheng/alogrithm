 // 超出时间限制
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ret;

        size_t s{}, e = k, sz{nums.size()};
        for (; e < sz + 1; ++e, ++s) {
            int max{INT_MIN};
            for (size_t i = s; i < e; ++i) {
                int val = nums.at(i);
                if (max < val) {
                    max = val;
                }
            }
            ret.push_back(max);
        }

        return ret;
    }
private:
    //priority_queue<int, vector<int>, greater<int>> heap;
    //priority_queue<int> heap;
};

int main()
{
    vector<int> nums {1,3,-1,   -3,5,    3,6,7};
    //vector<int> nums {5, 3, 4};

    Solution sol;
    vector<int> ret = sol.maxSlidingWindow(nums, 3);

    for (auto &&v : ret) {
        printf("%d ", v);
    }
    printf("\n");
}
