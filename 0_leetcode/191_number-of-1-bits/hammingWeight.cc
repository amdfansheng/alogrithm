#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        size_t count{};
        for (; n; ++count) {
            n &= n - 1;
        }
        return count;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int num = atoi(argv[1]);

    Solution s;
    printf("%d has %d 1\n", num, s.hammingWeight(num));
}


