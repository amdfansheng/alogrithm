// 冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。

//1.1 算法描述
//比较相邻的元素。如果第一个比第二个大，就交换它们两个；
//对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
//针对所有的元素重复以上的步骤，除了最后一个；
//重复步骤1~3，直到排序完成。
#include <cstdio>
#include <cstdlib>

void bubble(int *nums, size_t size)
{
    int pre = 1, cur = 0;

    for (size_t i = 0; i < size; --size) {
        if (!pre) return;

        cur = 0;
        printf("new cycle: %zu\n", size);
        for (size_t y = 0; y < size; ++y) {

            if (nums[y] <= nums[y + 1]) continue;

            int tmp = nums[y];
            nums[y] = nums[y + 1];
            nums[y + 1] = tmp;

            ++cur;
            printf("\tcur: %d\n", cur);
        }
        pre = cur;
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
    bubble(num, sz);
    dump(num, sz);
}
