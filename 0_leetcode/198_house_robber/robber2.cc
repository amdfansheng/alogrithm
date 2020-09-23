#include <stdio.h>


int rob(int* nums, int sz)
{
    if (!sz) return 0;
    if (sz == 1) return nums[0];
    if (sz == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

    // initialize
    int mark[sz];
    mark[0] = nums[0];
    mark[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    int ret = 0;
    for (int i = 2; i < sz; ++i) {
        int addi = mark[i - 2] + nums[i];
        mark[i] = mark[i - 1] >  addi ? mark[i - 1] : addi;
        if (mark[i] > ret) ret = mark[i];
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
