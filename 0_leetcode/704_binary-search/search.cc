#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        int left{}, right = nums.size() - 1; // 这里要减 1，否则 target 比最大值还大的话，最后会越界

        while (left <= right) { // 这里必须要加上等于，否则 nums 只有一个数的话，这个数查找不到, 因为上面 right 选取的是闭合区间，nums.size() - 1
            int mid = left + (right - left) / 2;
            printf("%d, %d, %d\n", left, mid, right);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int target = atoi(argv[1]);

    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    printf("%d\n", s.search(nums, target));
}
