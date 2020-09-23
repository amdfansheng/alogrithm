#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int getSum(int a, int b)
    {
        //int64_t la, lb;
        if (a < 0 && b < 0) {
            a = abs(a);
            vector<int> v1(a);
            while (b != 0) {
                v1.push_back(1);
                ++b;
            }
            int rst = v1.size();
            return -rst;
        }
        if (a >= 0 && b >= 0) {
            vector<int> v1(a);
            while (b != 0) {
                v1.push_back(1);
                --b;
            }
            return v1.size();
        }
        if (a > 0 && b < 0) {
            vector<int> v1(a);
            while (b != 0) {
                v1.pop_back();
                ++b;
            }
            return v1.size();
        }
        if (a < 0 && b > 0) {
            printf("a < 0, b > 0\n");
            vector<int> v1(b);
            while (a != 0) {
                v1.pop_back();
                ++a;
            }
            return v1.size();
        }
    }
};

int main (int argc, char *argv[])
{
    Solution s;
    printf("%d\n", s.getSum(atoi(argv[1]), atoi(argv[2])));
}
