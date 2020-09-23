#include <stdio.h>



int find_bmax(int *nums, int sz, int *index)
{
    while (*index - 1 > -1 && nums[*index - 1] > nums[*index]) --*index;
    printf("bmax index: %d, val: %d\n", *index, nums[*index]);
    return nums[*index];
}


int find_fmax(int *nums, int sz, int *index)
{
    while (*index + 1 < sz && nums[*index] < nums[*index + 1]) ++*index;
    printf("fmax index: %d, val: %d\n", *index, nums[*index]);
    return nums[*index];
}

int rob(int* nums, int sz)
{
    if (!sz) return 0;
    if (sz == 1) return nums[0];
    if (sz == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

    int mark[sz];
    int ret = 0;
    for (int i = 0; i < sz; ++i) {
        printf("i: %d, mark[i]: %d\n", i, mark[i]);
        //if (mark[i] == -1) continue;
        int sum = nums[i];
        for (int y = i + 2; y < sz; y += 2) {
            sum += find_fmax(nums, sz, &y);
            printf("after forward, sum: %d\n", sum);
            mark[y] = -1;
        }
        for (int y = i - 2; y > -1; y -= 2) {
            sum += find_bmax(nums, sz, &y);
            printf("after backward, sum: %d\n", sum);
            mark[y] = -1;
        }

        if (sum > ret) ret = sum;
        printf("ret: %d\n", ret);
    }
    return ret;
}

int main()
{
    //int v[] = {2, 7, 9, 3, 1};
    //printf("%d\n", rob(v, 5));
    //int v[] = {1, 2, 3, 1};
    //printf("%d\n", rob(v, 4));
    //int v[] = {2, 1, 1, 2};
    //printf("%d\n", rob(v, 4));
    //int v[] = {1, 3, 1, 3, 100};
    //printf("%d\n", rob(v, 5));
    //int v[] = {2, 4, 8, 9, 9, 3};
    //printf("%d\n", rob(v, 6));
    int v[] = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    printf("%d\n", rob(v, 37));
}
