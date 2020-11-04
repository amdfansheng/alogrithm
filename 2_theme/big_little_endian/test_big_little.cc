#include <cstdio>

void test_big_little()
{
    // 联合体的所有成员都从低地址开始存放。
    // 大端：低地址存放高位字节，小端：低地址存放低位字节
    union test {
        int i;
        char c;
    };

    test t;
    t.i = 1;

    if (t.c == 1)
        printf("little endian.\n");
    else
        printf("big endian.\n");
}

int main()
{
    test_big_little();
}
