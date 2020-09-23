// 116ms
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ret;

        size_t sz{nums.size()};
        for (size_t i = 0; i < k; ++i) {
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        ret.push_back(nums[window.front()]);

        for (size_t i = k; i < sz; ++i) {
            if (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }

            window.push_back(i);
            ret.push_back(nums[window.front()]);
        }
        return ret;
    }
private:
    deque<size_t> window; // only store nums index
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
