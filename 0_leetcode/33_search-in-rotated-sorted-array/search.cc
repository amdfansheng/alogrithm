#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int size = nums.size() - 1;
        if (size == -1) return -1;

        int left = 0, right = size;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) { // 前有序
                int ret = bsearch(nums, left, mid, target);
                if (ret != -1) return ret;
                left = mid + 1;
            } else { // 后有序
                int ret = bsearch(nums, mid, right, target);
                if (ret != -1) return ret;
                right = mid - 1;
            }
        }
        return -1;
    }

    int bsearch(const vector<int> &nums, int left, int right, int target)
    {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            printf("left: %d, mid: %d, right: %d, nums[mid]: %d\n", left, mid, right, nums[mid]);
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
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
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    Solution s;
    //vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums = {3, 1};
    s.dump(nums);

    int target = atoi(argv[1]);
    int ret = s.search(nums, target);
    printf("target: %d, index: %d\n", target, ret);
}
