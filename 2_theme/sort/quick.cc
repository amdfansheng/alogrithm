#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    void quickSort(vector<int> &nums)
    {
        quickSortIn(nums, 0, nums.size() - 1);
    }

    void  quickSortIn(vector<int> &nums, int beg, int end)
    {
        printf("begin: %d, end: %d\n", beg, end);
        if (beg >= end) return;

        int pivot_point = partition1(nums, beg, end);
        printf("pivot index: %d\n", pivot_point);

        quickSortIn(nums, beg, pivot_point - 1);
        quickSortIn(nums, pivot_point + 1, end);
    }

    // 单边扫描法
    int partition(vector<int> &nums, int beg, int end)
    {
        int pivot = beg;
        int mark = beg + 1;
        for (int i = mark; i <= end; ++i) {
            if (nums[i] < nums[pivot]) {
                printf("\tswap, i: %d, mark: %d\n", i, mark);
                swap(nums, i, mark);
                ++mark;
                dump(nums);
            }
        }

		printf("\tswap, mark - 1: %d, pivot: %d\n", mark - 1, pivot);
        swap(nums, mark - 1, pivot); // 注意，这儿有个坑，基准值和mark交换时，mark要减一，因为在扫描时加了一
		dump(nums);
        return mark - 1;
    }

	//双边扫描法, 逻辑没有理解
	int partition1(vector<int> &A, int low, int high) {
	  int pivot = A[low];
	  while (low < high) {
	    while (low < high && A[high] >= pivot) { --high; }
		printf("\thigh: %d\n\t", high);
	    A[low] = A[high];
		dump(A);
	    while (low < high && A[low] <= pivot) { ++low; }
		printf("\tlow: %d\n\t", low);
	    A[high] = A[low];
		dump(A);
	  }
	  A[low] = pivot;
      dump(A);
	  return low;
	}

    void swap(vector<int> &nums, int i, int y)
    {
        int temp = nums[i];
        nums[i] = nums[y];
        nums[y] = temp;
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
    s.dump(nums);
    s.quickSort(nums);
    s.dump(nums);
}
