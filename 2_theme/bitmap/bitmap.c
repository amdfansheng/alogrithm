// 输入：一个最多包含n个正整数的文件，每个数都小于n，其中n=10^7。
// 如果在输入文件中有任何正数重复出现就是致命错误。没有其他数据与该正数相关联。

//输出：按升序排列的输入整数的列表。

//约束：最多有（大约）1MB的内存空间可用，有充足的磁盘存储空间可用。运行时间最多几分钟，运行时间为10秒就不需要进一步优化。
#include<stdio.h>
#include<stdlib.h>

#define CHAR_BIT    8            // char类型占用的bit位数
#define SHIFT       3            // 右移的位数
#define MAX_NUM     10000000/8
#define BIT_SIZE    10000000     // 所需比特位总数量
#define MAX_STR     10           // 一个整数所需最大字符数

#define INPUT_FILE  "srcNum.txt"
#define OUTPUT_FILE "dstNum.txt"

/*将整数对应的比特位置1*/
int putIntoBitMap(char *bitmap, int num)
{
    int byte = num >> SHIFT; // 相当于除8
    char bit = 1 << num % CHAR_BIT;
    bitmap[byte] |= (char)bit;
    return 0;
}

/*判断整数是否在位图中*/
int isInBitMap(char *bitmap, int num)
{
    int byte = num >> SHIFT;
    char bit = 1 << num % CHAR_BIT;
    if (bitmap[byte] & (char)bit)
        return 1;
    else
        return 0;
}

int main(void)
{
    /*打开源文件*/
    FILE *in = fopen(INPUT_FILE, "r");
    if(NULL == in) { printf("open src num failed"); return -1; }

    /*申请位图相关内存，并初始化为0*/
    char *bitmap = (char*)calloc(MAX_NUM, sizeof(char));
    if (NULL == bitmap) { fclose(in); return -1; }

    int num = 0;
    char string[MAX_STR] = {0};
    /*循环读取文件中的整数，并将对应位置1*/
    while (fgets(string, MAX_STR, in) != NULL) {
        num = atoi(string);
        putIntoBitMap(bitmap, num);
        //printf("%d\n",num);
    }
    fclose(in);
    /*遍历位图中的比特位，为1，则输出整数到文件中*/
    FILE *out = fopen(OUTPUT_FILE, "w+");
    if(NULL == out) {
        printf("open dst num failed");
        free(bitmap);
        bitmap = NULL;
        return -1;
    }
    int i;
    for (i = 0; i < BIT_SIZE; i++) {
        if (isInBitMap(bitmap , i)) {
            fprintf(out, "%d\n", i);
            //printf("%d\n",i);
        }
    }
    fclose(out);
    free(bitmap);
    bitmap = NULL;
    return 0;
}
