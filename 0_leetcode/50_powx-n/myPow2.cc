#include <cstdio>
#include <cstdlib>

class Solution {
public:
    double quickMul(double x, int n)
    {
        if (!x || n == 1) return x;
        if (n == 0) return 1.0;

        double ret = quickMul(x, n / 2);
        return n % 2 ? ret * ret * x : ret * ret;
    }

    double myPow(double x, int n)
    {
        return n < 0 ? 1.0 / quickMul(x, n) : quickMul(x, n);
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
