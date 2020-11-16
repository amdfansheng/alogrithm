#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    // 双指针，最好的解法
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target){
                ++left;
            } else if (sum > target) {
                --right;
            }
        }
        return {-1, -1};
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int target = atoi(argv[1]);

    vector<int> nums = {2, 7, 11, 15};
    for (auto &&v : nums) {
        printf("%d ", v);
    }
    printf("\n");

    Solution s;
    auto res = s.twoSum(nums, target);
    printf("%d %d\n", res[0], res[1]);
}
