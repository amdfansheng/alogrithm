// 全排列，经典回溯问题
// 通过交换元素
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int size = nums.size();
        if (size < 1) return vector<vector<int>>();
        if (size < 2) return vector<vector<int>>{nums};

        vector<vector<int>> ret;
        permute_in(ret, nums, size);
        return ret;
    }

    void permute_in(vector<vector<int>> &ret, vector<int> &nums, int k) // 路径，选择列表
    {
        // 满足结束条件
        if (k == 1) {
            ret.push_back(nums);
            return;
        }

        for (int i = 0; i < k; ++i) {
            // 做选择
            int tmp = nums[k - 1];
            nums[k - 1] = nums[i];
            nums[i] = tmp;

            permute_in(ret, nums, k - 1);

            // 撤消选择
            tmp = nums[i];
            nums[i] = nums[k - 1];
            nums[k - 1] = tmp;
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 4};

    Solution s;
    vector<vector<int>> result = s.permute(nums);
    for (auto &&vec : result) {
        for (auto &&v : vec) {
            printf("%d ", v);
        }
        printf("\n");
    }
}
