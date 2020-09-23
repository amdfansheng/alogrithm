#include <cstdio>
#include <cstdlib>

class Solution {
public:
    double myPow(double x, int n)
    {
        if (!x || n == 1) return x;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double ret = 1.0;
        while (n > 0) {
            if (n & 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 3) return -1;
    double d = atof(argv[1]);
    int n = atoi(argv[2]);
    Solution s;
    printf("%f pow %d: %f\n", d, n, s.myPow(d, n));
}
