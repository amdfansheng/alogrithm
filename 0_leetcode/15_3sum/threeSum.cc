// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
//
// 注意：答案中不可以包含重复的三元组。
// 链接：https://leetcode-cn.com/problems/3sum
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        size_t sz = nums.size();
        for (size_t i = 0; i < sz; ++i) {
            auto two_ret = twoSum(nums, 0-nums[i], i);
            if (!two_ret.size()) continue;
            ret.push_back({nums[i], nums[two_ret[0]], nums[two_ret[1]]});
        }

        return ret;
    }

    vector<int> twoSum(vector<int> &nums, int target, size_t skip)
    {
        unordered_map<int, size_t> hmap;
        size_t sz = nums.size();
        for (size_t i = 0; i < sz; ++i) {
            if (i == skip) continue;
            int sec = target - nums[i];
            hmap.emplace(nums[i], i);
            auto it = hmap.find(sec);
            if (it == hmap.end()) continue;
            if (it ->second == i) continue;
            return {int(it->second), int(i)};
        }
        return {};
    }
};

int main ()
{
    Solution s;
    vector<int> input {-1, 0, 1, 2, -1, -4};
    for (auto &&v : input) {
        printf("%d ", v);
    }
    printf("\n");

    auto rst = s.threeSum(input);
    for (auto &&vec : rst) {
        for (auto &&v : vec) {
            printf("%d ", v);
        }
        printf("\n");
    }
}
