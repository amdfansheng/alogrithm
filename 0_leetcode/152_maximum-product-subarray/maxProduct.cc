// 找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
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
        int size = nums.size();
        if (!size) return 0;
        if (size == 1) return nums[0];

        vector<vector<int>> memo;
        memo.resize(size);
        for (int i = size - 1; i >= 0; --i) {
            memo[i].resize(i + 1);
            memo[i][i] = nums[i];
            if (memo[i][i] > ret) ret = memo[i][i];
        }

        for (int i = size - 1; i >= 0; --i ) { // row
            for (int j = i - 1; j >= 0; --j) { // column
                memo[i][j] = nums[j] * memo[i][j + 1];
                if (memo[i][j] > ret) ret = memo[i][j];
                //printf("memo[%d][%d]: %d, ret: %d\n", i, j, memo[i][j], ret);
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
        {-5,2,4,1,-2,2,-6,3,-1,-1,-1,-2,-3,5,1,-3,-4,2,-4,6,-1,5,-6,1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,1,1,1,-1,1,1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,1,1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,1,1,1,-1,1,-1,1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,-1,1,1,1,-1,1,1,1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,1,1,1,-1,1,1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,1,1,1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,1,-1,1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,1,1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,1,1,1,1,1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,-1,1,-1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,1,1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,1,1,1,1,-1,-1,1,1,1,1,1,-1,1,1,1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,1,1,1,-1,-1,1,1,1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,1,1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,1,1,1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,1,1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,1,1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,1,-1,1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,1,1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,1,1,1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,-1,1,1,1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,1,-1,-1,1,-1,1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,1,1,-1,1,1,-1,1,1,1,1,-1,1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,1,1,1,1,1,1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,1,1,1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,1,-1,1,-1,1,-1,1,1,1,1,-1,1,1,1,-1,1,1,1,1,1,-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,1,1,1,-1,1,1,1,-1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,1,1,1,1,1,1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,1,1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,1,-1,1,1,-1,1,1,1,1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,1,-1,1,1,-1,1,1,-1,1,1,1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,-1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,1,1,1,1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,1,1,1,-1,-1,-1,1,1,-1,1,1,1,1,1,1,1,1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,1,1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,1,1,-1,-1,1,-1,1,1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,1,1,-1,1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,1,1,-1,1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,1,-1,1,1,1,1,-1,1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,1,-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,-1,-1,-1,1,-1,1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,1,1,1,1,1,1,-1,1,-1,1,1,-1,-1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,-1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,1,-1,1,-1,1,1,1,1,1,-1,1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,-1,1,1,-1,1,-1,-1,1,1,-1,1,1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,1,1,1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,1,-1,1,1,-1,1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,1,1,1,1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,1,1,-1,1,1,-1,1,1,1,1,1,1,-1,1,1,1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,-1,1,1,1,1,-1,1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,1,1,-1,1,1,1,-1,1,1,1,1,1,1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,1,1,1,1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,1,1,1,1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,-1,1,1,-1,1,1,1,1,1,-1,1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,1,1,1,1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,1,1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,1,1,1,1,1,1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,1,1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,1,1,1,1,1,1,1,1,1,-1,1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,1,1,1,1,1,1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,-1,-1,1,1,1,1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,1,-1,1,1,-1,-1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,1,1,1,1,1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,1,1,1,1,1,1,-1,1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,1,1,-1,1,1,-1,1,-1,-1,1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,1,1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,1,1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,1,-1,-1,-1,1,1,1,1,1,1,-1,-1,1,-1,1,1,-1,1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,1,1,1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,-1,1,-1,1,-1,1,-1,-1,1,1,1,-1,1,-1,1,1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,1,1,1,1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,1,-1,1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,1,1,1,1,1,1,1,1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,1,1,1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,1,1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,-1,1,1,1,-1,1,-1,1,1,1,1,-1,1,1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,1,-1,1,1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,1,1,-1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,1,1,1,-1,1,1,1,1,1,1,1,-1,1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,1,1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,1,1,1,1,-1,1,1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,1,-1,1,1,1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,1,1,1,1,-1,1,-1,-1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,1,1,1,1,1,1,-1,-1,1,1,1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,-1,-1,1,1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,1,-1,1,1,-1,1,1,-1,1,1,1,1,1,-1,1,1,1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,1,1,1,-1,1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,1,1,1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,1,-1,1,1,-1,1,1,1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,1,1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,-1,1,1,-1,1,1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,1,1,-1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,1,1,-1,1,1,1,1,-1,1,1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,1,1,-1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,1,-1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,-1,1,1,1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,1,1,1,1,-1,1,1,1,1,-1,1,1,1,1,-1,1,-1,-1,1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,-1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,1,1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,1,1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,1,1,-1,1,1,-1,1,1,-1,1,-1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,1,1,-1,1,-1,-1,1,-1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,1,1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,1,1,-1,-1,1,1,1,1,-1,1,-1,1,-1,1,-1,1,1,-1,1,1,1,1,1,-1,1,1,-1,1,-1,-1,1,1,1,1,-1,1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,1,1,-1,-1,-1,-1,-1,1,1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,1,1,-1,1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,1,1,-1,-1,1,1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,-1,1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,1,-1,1,-1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,1,-1,-1,1,1,1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,1,1,-1,1,1,-1,1,-1,1,1,1,1,1,1,-1,-1,1,1,1,-1,1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,1,-1,-1,1,1,1,1,1,1,1,1,1,-1,1,1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,1,1,-1,-1,1,-1,1,1,1,-1,1,1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,1,1,-1,1,-1,1,-1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,-1,1,1,1,-1,1,1,1,1,1,1,-1,1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,1,1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,1,1,1,1,1,1,1,-1,1,1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,1,1,-1,1,1,-1,-1,1,-1,1,-1,1,1,1,1,1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,1,1,1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,1,1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,1,1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,1,1,-1,1,-1,1,1,1,-1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,1,1,-1,1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,1,1,1,-1,1,-1,1,1,1,1,1,1,1,-1,-1,1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,1,1,1,-1,1,-1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,1,1,-1,1,1,1,1,-1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,1,1,1,1,-1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,-1,-1,1,-1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,-1,1,1,1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,-1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,1,1,-1,1,1,1,1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,1,1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,1,1,1,-1,1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,1,1,1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,1,1,1,1,1,1,1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,1,1,1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,1,1,1,-1,-1,1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,-1,1,-1,1,1,1,-1,1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,1,1,1,1,1,1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,1,1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,1,1,1,1,1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,1,1,-1,-1,1,1,-1,-1,1,1,1,-1,1,-1,1,1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,1,1,1,1,-1,1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,-1,1,-1,1,1,1,-1,1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,-1,-1,-1,1,1,1,1,1,1,1,-1,1,1,1,-1,1,-1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,1,1,1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,1,1,1,1,1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,-1,-1,-1,1,1,1,1,1,1,1,-1,1,-1,1,-1,1,1,1,-1,1,1,1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,1,1,1,-1,-1,-1,-1,1,1,1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,1,1,1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,1,-1,-1,1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,1,1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1}
    };

    Solution s;
    printf("%d\n", s.maxProduct(nums[ind]));
}
