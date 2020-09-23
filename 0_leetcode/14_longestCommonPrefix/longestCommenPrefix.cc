//#include <stdint.h>
//#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string rst;
        size_t strs_sz = strs.size();
        if (!strs_sz) return rst;
        if (strs_sz == 1) return strs[0];

        size_t first_str_sz = strs[0].size();
        rst.reserve(first_str_sz);
        for (size_t i = 0; i < first_str_sz; ++i) {
            char tmp = strs[0][i];
            for (size_t j = 1; j < strs_sz; ++j) {
                if (tmp != strs[j][i]) return rst;
            }
            rst[i] = tmp;
        }
        return rst;
    }
};

int main(int argc, char *argv[])
{
    vector<string> strs;
    for (int i = 1; i < argc; ++i) {
        //printf("%s\n", argv[i]);
        strs.emplace_back(argv[i]);
    }
    Solution s;
    printf("%s\n", s.longestCommonPrefix(strs).data());
}
