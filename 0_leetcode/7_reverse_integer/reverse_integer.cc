#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

const int32_t min = 0x80000000;
const int32_t max = 0x7fffffff;

class Solution {
public:
    int reverse(int x)
    {
		bool s {false};
        unsigned unum {0};
		if (x < 0) {
            s = true;
            unum = (unsigned)-x;
        } else unum = (unsigned)x;

        int i {0};
        int tmp[32] = {0};
        do {
            tmp[i++] = unum % 10;//取unum的最后一位
            unum /= 10;//unum去掉最后一位

        } while (unum);//直至unum为0退出循环

        int64_t rst {0};
        for (int j = 0; j < i; ++j) {
            if (!tmp[j]) continue;
            rst += tmp[j] * pow(10, i - 1 - j);
        }

        if (rst < min || rst > max) return 0;
        return s?-rst:rst;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    printf("%d\n", min);
    printf("%d\n", max);
    printf("input: %d\n", atoi(argv[1]));

    printf("reverse: %d\n", s.reverse(atoi(argv[1])));
}
