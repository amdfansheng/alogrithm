#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution {
public:
    // 寻找 k 使得k^2 <= x
    int mySqrt(int x)
    {
        if (x <= 0) return 0;

        uint64_t left = 0, right = x, mid{};
        while (left <= right) {
            mid = left + (right - left) / 2;
            uint64_t pow = mid * mid;
            if (pow == x) {
                return mid;
            } else if (pow < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        //return left - 1;
        return mid;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int n = atoi(argv[1]);
    printf("sqrt: %f\n", sqrt(n));

    Solution s;
    printf("mySqrt: %d\n", s.mySqrt(n));
}


