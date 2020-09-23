// 插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

//3.1 算法描述
//一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：

//从第一个元素开始，该元素可以认为已经被排序；
//取出下一个元素，在已经排序的元素序列中从后向前扫描；
//如果该元素（已排序）大于新元素，将该元素移到下一位置；
//重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
//将新元素插入到该位置后；
//重复步骤2~5。
#include <cstdio>
#include <cstdlib>

void selection(int *nums, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        size_t pos{i};
        for (size_t y = i; y < size; ++y) {
            if (nums[y] >  nums[pos]) continue;
            pos = y;
        }
        int tmp = nums[i];
        nums[i] = nums[pos];
        nums[pos] = tmp;
    }
}

void dump(int *nums, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int num[] = {8, 6, 7, 3, 5, 0, 9, 1, 4, 2};
    size_t sz = sizeof(num)/sizeof(num[0]);

    dump(num, sz);
    selection(num, sz);
    dump(num, sz);
}
