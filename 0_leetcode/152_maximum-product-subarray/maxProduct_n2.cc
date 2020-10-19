// 找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
// 超出时间限制
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int ret = INT_MIN;

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return nums[0];

        size_t size = nums.size();
        for (int i = 0; i < size; ++i) {
            int tmp = nums[i];
            if (tmp > ret) ret = tmp;
            for (int j = i + 1; j < size; ++j) {
                tmp *= nums[j];
                if (tmp > ret) ret = tmp;
            }
        }

        return ret;
    }

};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int ind = atoi(argv[1]);
    vector<vector<int>> nums = {
        {2, 3, -2, 4},
        {-2, 0, -1},
        {-3, -1, -1},
        {0, 2},
    };

    Solution s;
    printf("%d\n", s.maxProduct(nums[ind]));
}
