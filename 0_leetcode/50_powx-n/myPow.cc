#include <cstdio>
#include <cstdlib>

class Solution {
public:
    double myPow(double x, int n)
    {
        if (!x || n == 1) return x;
        if (n == 0) return 1;

        double ret = myPow(x, abs(n) / 2);
        ret *= ret;
        if (n % 2) ret *= x;
        if (n < 0) ret = 1 / ret;
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
