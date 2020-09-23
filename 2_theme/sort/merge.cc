#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    void mergeSort(vector<int> &nums)
    {
        mergeSortIn(nums, 0, nums.size() - 1);
    }

    void  mergeSortIn(vector<int> &nums, int beg, int end)
    {
        if (beg >= end) return;

        int mid = beg + end >> 1;

        mergeSortIn(nums, beg, mid);
        mergeSortIn(nums, mid + 1, end);

        merge(nums, beg, end);
    }

    void merge(vector<int> &nums, int beg, int end)
    {
        int mid = beg + end >> 1;

        vector<int> tmp;
        tmp.reserve(end - beg + 1);

        int i = beg, j = mid + 1, k = 0;
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
            //printf("%d\n", tmp[k - 1]);
        }

        int start = i, stop = mid;
        if (j <= end ) {
            start = j;
            stop = end;
        }

        while (start <= stop) {
            tmp[k++] = nums[start++];
            //printf("%d\n", tmp[k - 1]);
        }

        for (int i = 0; i < end - beg + 1; ++i) {
            nums[beg + i] = tmp[i];
        }
    }

    void dump(const vector<int> &nums)
    {
        for (auto &&num : nums) {
            printf("%d, ", num);
        }
        printf("\n");
    }
};

int main()
{
    vector<int> nums = {2, 1, -1, 5, 8, -2, 3, 9, 7, 6};
    //vector<int> nums = {1, 5, 6, 2, 3, 4};
    Solution s;
    s.mergeSort(nums);
    s.dump(nums);
}
