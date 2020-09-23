#include <cstdio>
#include <cstdlib>

class Solution {
public:
    int fib(int N)
    {
        // base
        //int memo[N + 1];
        int *memo = new int[N + 1];
        memo[0] = 0;
        memo[1] = 1;

        for (int i = 2; i < N + 1; ++i) {
            memo[i] = memo[i-2] + memo[i-1];
        }

        int ret = memo[N];
        delete [] memo;
        return ret;
        //return memo[N];
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    Solution s;
    int n = atoi(argv[1]);
    printf("%d: %d\n", n, s.fib(n));
}
