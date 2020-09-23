#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int getSum(int a, int b)
    {
        while (b) {
            auto up = ((unsigned)a & b) << 1;
            a = a ^ b;
            b = up;
        }
        return a;
    }
};

int main (int argc, char *argv[])
{
    Solution s;
    printf("%d\n", s.getSum(atoi(argv[1]), atoi(argv[2])));
}
