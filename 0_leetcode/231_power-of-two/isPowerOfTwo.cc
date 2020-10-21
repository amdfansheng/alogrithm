#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && !(n & n - 1); // 所有负数都不是 2 的幂
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int num = atoi(argv[1]);

    Solution s;
    printf("%d is power of 2: %s\n", num, s.isPowerOfTwo(num) ? "yes" : "no");
}
