// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
//
// 注意：答案中不可以包含重复的三元组。
// 链接：https://leetcode-cn.com/problems/3sum
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < sz - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = sz - 1;
            while (left != right) {
                if (left > i + 1 && nums[left] == nums[left -1]) { ++left; continue; }
                if (right <  sz - 1 && nums[right] == nums[right + 1]) { --right; continue; }
                int cur = nums[i] + nums[left] + nums[right];
                printf("i: %d, left: %d, right: %d, cur: %d\n", i, left, right, cur);
                if (!cur) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left; continue;
                }
                if (cur > 0) { --right; continue; }
                if (cur < 0) { ++left; continue; }
            }
        }
        return result;
    }
};

int main ()
{
    Solution s;
    //vector<int> input {-1, 0, 1, 2, -1, -4};
    //vector<int> input {0,0,0,0};
    vector<int> input {0,2,2,3,0,1,2,3,-1,-4,2};
    sort(input.begin(), input.end());
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
