// 比特位计数
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num)
    {
        //                    1  2  3
        vector<int> ret = {0, 1, 1, 2};
        ret.resize(num + 1);
        int pow = 1;
        for (; pow <= num; pow *= 2) {
            ret[pow] = 1;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int num = atoi(argv[1]);
    printf("num: %d\n", num);

    Solution s;
    vector<int> ret = s.countBits(num);
    for (auto &&n : ret) {
        printf("%d ", n);
    }
}

