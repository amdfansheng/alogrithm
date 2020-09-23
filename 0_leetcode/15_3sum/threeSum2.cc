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
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            printf("i: %d:%d\n", i, nums[i]);
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0) {
                printf("nums[%d]:%d > 0\n", i, nums[i]);
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
                printf("nums[i] == nums[i - 1], i: %d\n", i);
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                printf("\tj: %d:%d\n", j, nums[j]);
                if (j > i + 2 &&
                    nums[j]   == nums[j-1] &&
                    nums[j-1] == nums[j-2]) { // 三元组元素b去重
                    printf("nums[j] == nums[j-1] == nums[j-2]\n");
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                printf("\tc: %d\n", c);
                if (set.find(c) != set.end()) {
                    printf("\tfound c: [%d, %d, %d]\n", nums[i], nums[j], c);
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);// 三元组元素c去重
                } else {
                    printf("\tnot found c, insert %d\n", nums[j]);
                    set.insert(nums[j]);
                }
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
