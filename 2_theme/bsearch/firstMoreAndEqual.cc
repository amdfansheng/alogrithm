// 查找第一个 大于等于 给定值的元素
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

// 自己写的
int firstEqual(const vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        printf("left: %d, mid: %d, right: %d, nums[mid]: %d\n", left, mid, right, nums[mid]);
        if (target == nums[mid]) {
            int i = mid;
            while (i >= 0 && nums[i] == target) { --i; }
            return i + 1;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// 简洁的写法
int firstEqual2(const vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        printf("left: %d, mid: %d, right: %d, nums[mid]: %d\n", left, mid, right, nums[mid]);
        if (target <= nums[mid]) {
            if (mid == 0 || nums[mid - 1] < target) return mid;
            else right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

void dump(const vector<int> &nums)
{
    for (auto &&v : nums) {
        printf("%d, ", v);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    vector<int> nums = {2, 9, 23, 11, 33, 8, 23, 7, 10, 15, 83, 23};
    sort(nums.begin(), nums.end());
    dump(nums);

    int target = atoi(argv[1]);
    int ret = firstEqual2(nums, target);
    printf("target: %d, index: %d\n", target, ret);
}
