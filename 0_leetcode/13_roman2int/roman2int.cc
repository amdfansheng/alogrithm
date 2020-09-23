//#include <stdint.h>
#include <cstdio>
//#include <cstdlib>
#include <string>

using namespace std;

int MAP['Z'] = {0};
bool is_build = false;

class Solution {
public:
    int romanToInt(string s)
    {
        if (!is_build) {
            MAP['I'] = 1;
            MAP['V'] = 5;
            MAP['X'] = 10;
            MAP['L'] = 50;
            MAP['C'] = 100;
            MAP['D'] = 500;
            MAP['M'] = 1000;
            is_build = true;
        }

        int rst {0};
        size_t sz = s.size();
        for (size_t i = 0; i < sz; ++i) {
            switch (s[i]) {
            case 'I':
                rst += (s[i+1] == 'V' || s[i+1] == 'X')?-MAP[s[i]]:MAP[s[i]];
                break;
            case 'X':
                rst += (s[i+1] == 'L' || s[i+1] == 'C')?-MAP[s[i]]:MAP[s[i]];
                break;
            case 'C':
                rst += (s[i+1] == 'D' || s[i+1] == 'M')?-MAP[s[i]]:MAP[s[i]];
                break;
            case 'V':
            case 'L':
            case 'D':
            case 'M':
                rst += MAP[s[i]];
                break;
            default:
                return 0;
            }
        }
        return rst;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    printf("%d\n", s.romanToInt(argv[1]));
}
