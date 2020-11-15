#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res(2);
        res[0] = left_bound(nums, target);
        res[1] = right_bound(nums, target);
        return res;
    }

    //  返回值含义：小于 target 的元素有几个
    int left_bound(vector<int> &nums, int target)
    {
        int left{}, right = nums.size() - 1;

        while (left <= right) { // 左闭右闭
            int mid = left + (right - left) / 2;
            printf("left: %d, mid: %d, right: %d\n", left, mid, right);
            if (nums[mid] == target)
                right = mid - 1; // 收缩右侧边界
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }

        printf("final left: %d, right: %d\n", left, right);
        if (left >= nums.size() || nums[left] != target) return -1;
        return left;
    }

    int right_bound(vector<int> &nums, int target)
    {
        int left{}, right = nums.size() - 1;

        while (left <= right) { // 左闭右闭
            int mid = left + (right - left) / 2;
            printf("left: %d, mid: %d, right: %d\n", left, mid, right);
            if (nums[mid] == target)
                left = mid + 1; // 收缩左侧边界
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }

        printf("final left: %d, right: %d\n", left, right);
        if (right < 0 || nums[right] != target) return -1;
        return right;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int target = atoi(argv[1]);

    Solution s;
    vector<int> nums = {1, 2, 2, 4};

    auto res = s.searchRange(nums, target);
    printf("[%d, %d]\n", res[0], res[1]);
}
