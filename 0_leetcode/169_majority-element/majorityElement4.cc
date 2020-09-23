// 分治化, 最差的解法
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int count_in_range(vector<int>& nums, int target, int lo, int hi)
    {
        int count = 0;

        for (int i = lo; i <= hi; ++i)
            if (nums[i] == target) ++count;

        printf("lo: %d, hi: %d, target: %d, count: %d\n", lo, hi, target, count);
        return count;
    }

    int majority_element_rec(vector<int>& nums, int lo, int hi)
    {
        printf("lo: %d, hi: %d\n", lo, hi);

        if (lo == hi) return nums[lo];
        int mid = (lo + hi) / 2;

        int left_majority = majority_element_rec(nums, lo, mid);
        int right_majority = majority_element_rec(nums, mid + 1, hi);

        if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2) {
            printf("left_majority: %d\n", left_majority);
            return left_majority; // 大于半数，直接返回
        }
        if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2) {
            printf("right_majority: %d\n", right_majority);
            return right_majority; // 大于半数，直接返回
        }

        printf("not more than %d\n", (hi - lo + 1) / 2);
        return -1; // 一样多，返回1个非法值
    }
public:
        int majorityElement(vector<int>& nums)
        {
                return majority_element_rec(nums, 0, nums.size() - 1);
        }
};

int main()
{
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    //vector<int> v = {3, 2, 3};
    Solution s;
    printf("majority: %d\n", s.majorityElement(v));
}
