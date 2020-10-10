#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class Solution {
public:
    // 寻找 k 使得k^2 <= x
    int mySqrt(int x)
    {
        int left = 0, right = x, ans{-1};
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
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


