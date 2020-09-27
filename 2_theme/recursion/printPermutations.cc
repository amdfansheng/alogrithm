#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

// n 个数据的排列”问题，就可以分解成 n 个“n−1 个数据的排列”的子问题。
// 假设数组中存储的是1，2， 3...n。
// f(1,2,...n) = {最后一位是1, f(n-1)} + {最后一位是2, f(n-1)} +...+{最后一位是n, f(n-1)}。
// k 表示要处理的子数组的数据个数
void printPermutations(vector<int> &nums, int k)
{
    if (k == 1) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < k; ++i) {
        //printf("k: %d, i: %d , ", k, i);
        int tmp = nums[i];
        nums[i] = nums[k-1];
        nums[k-1] = tmp;

        printPermutations(nums, k - 1);

        tmp = nums[i];
        nums[i] = nums[k-1];
        nums[k-1] = tmp;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int k = atoi(argv[1]);

    vector<int> nums = {1, 2, 3, 4};
    printPermutations(nums, k);
}
