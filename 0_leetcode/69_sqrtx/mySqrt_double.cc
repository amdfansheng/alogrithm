#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution {
public:
    // 寻找 k 使得k^2 <= x
    double mySqrt(double x)
    {
        uint64_t count{};
        double left = 0.0, right = x;
        //while (left < right) {
        while (true) {
            if (fabs(right - left) < 1e-7) {
                printf("count: %lu\n", count);
                return left;
            }
            double mid = left + (right - left) / 2;
            if (mid < x / mid)  left = mid;
            else right = mid;
            ++count;
        }
        return left;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int n = atoi(argv[1]);
    printf("sqrt: %f\n", sqrt(n));

    Solution s;
    printf("mySqrt: %f\n", s.mySqrt(n));
}


