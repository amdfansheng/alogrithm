#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 1) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int last = 2, llast = 1;

        int res{};
        for (int i = 2; i < n; ++i) {
            res = llast + last;
            llast = last;
            last = res;
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int n = atoi(argv[1]);
    Solution s;
    printf("stairs: %d, method: %d\n", n, s.climbStairs(n));
}
