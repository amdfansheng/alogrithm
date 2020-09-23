#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        auto it = nums.begin();
        auto it_end = nums.end();
        for (; it != it_end; ++it) {
            auto second = target - *it;
            auto first = lower_bound(it + 1, it_end, second);
            if (first != it_end && !(second < *first)) {
                return {(int)(it - nums.begin()), (int)(first - nums.begin())};
            }
        }
        return {};
    }
};

int main ()
{
    Solution s;
    vector<int> input {8, 5, 9, 60, 30, 2, 7, 11, 15};
    auto rst = s.twoSum(input, 9);
    if (rst.size()) {
        for (auto &&v : rst) {
            printf("%d ", v);
        }
        printf("\n");
    }
}
