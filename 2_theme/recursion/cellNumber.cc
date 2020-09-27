// 1 个细胞的生命周期是 3 小时，1 小时分裂一次。求 n 小时后，容器内有多少细胞？
// f(n) = 2f(n - 1) - f(n - 3)
// 转化为dp后的代码
#include <cstdlib>
#include <cstdio>

int cellNumber(int hours)
{
    if (hours < 0) return 0;
    int memo[3] = {1, 2, 4};
    if (hours < 3) return memo[hours];

    int ret{};
    for (int i = 2; i < hours; ++i) {
        int cur  = memo[2];
        int last = memo[1];
        int dead = memo[0];
        ret = cur * 2 - dead;

        memo[2] = ret;
        memo[1] = cur;
        memo[0] = last;
    }
    return ret;
}

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int hour = atoi(argv[1]);

    printf("cells after %d hours: %d\n", hour, cellNumber(hour));
}
