//#include <stdint.h>
//#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    Solution() {
        map['('] = ')';
        map['['] = ']';
        map['{'] = '}';
    }

    bool isValid(string s)
    {
        size_t sz = s.size();
        if (!sz) return true;
        if (sz % 2) return false;

        char *start = &s[0];
        //char *end = &s[sz - 1];
        char *end = &s[sz];
        //printf("end char: %c\n", *end);
        size_t remain = sz;
        while (remain) {
            printf ("remain size: %zu, %s\n", remain, s.data());
            switch (*start) {
            case '(':
            case '[':
            case '{': {
                printf("left: %c\n", *start);
                char *cursor = start + 1;
                for (; cursor < end; cursor += 2) {
                    if (*cursor != map[*start]) {
                        printf("skip: %c\n", *cursor);
                        continue;
                    }
                    printf("map right char: %c\n", *cursor);
                    *cursor = '#';
                    remain -= 2;
                    break;
                }
                if (cursor >= end) return false;
                ++start;
                break;
            }
            case '#':
                printf("skip: %c\n", *start);
                ++start;
                break;
            default:
                printf("other char: %c\n", *start);
                return false;
            }
        }
        return true;
    }

    char map[128] = {0};
};

int main(int argc, char *argv[])
{
    Solution s;
    printf("%d\n", s.isValid(argv[1]));
}
