#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        auto beg = nums.begin(), it = beg;
        auto it_end = nums.end();
        for (; it != it_end; ++it) {
            auto second = target - *it;
            for (auto it2 = it + 1; it2 != it_end; ++it2) {
                if (*it2 != second) continue;
                return {int(it - beg), int(it2 - beg)};
            }
        }
        return {};
    }
};

int main ()
{
    Solution s;
    vector<int> input {8, 5, 9, 60, 30, 2, 7, 11, 15};
    auto rst = s.twoSum(input, 17);
    if (rst.size()) {
        for (auto &&v : rst) {
            printf("%d ", v);
        }
        printf("\n");
    }
}
