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

        vector<char> stack;
        for (auto &&v : s) {
            switch (v) {
            case '(':
            case '[':
            case '{':
                stack.push_back(v);
                break;
            default:
                if (!stack.size()) break;
                if (stack.size() > s.size() / 2) return false;
                if (map[stack.back()] == v) {
                    stack.erase(stack.end() - 1);
                }
            }
            //printf("%c ", v);
        }
        return stack.size()?false:true;
    }

    char map[128] = {0};
};

int main(int argc, char *argv[])
{
    Solution s;
    printf("%d\n", s.isValid(argv[1]));
}
