#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;
        if (haystack.size() < needle.size()) return -1;

        int ret{-1};
        size_t hsz = haystack.size();
        size_t nsz = needle.size();
        for (size_t h = 0; h < hsz; ++h) {
            if (hsz - h < nsz) break;
            if (haystack[h] != needle[0]) continue;
            size_t n = 0;
            for (size_t h2 = h; n < nsz; ++h2, ++n) {
                //fprintf(stderr, "%c : %c\n", haystack[h2], needle[n]);
                if (haystack[h2] != needle[n]) { break; }
            }
            //fprintf(stderr, "H: %zu\n", h);
            if (n == nsz) return h;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 3) return -1;

    Solution s;
    fprintf(stderr, "%d\n", s.strStr(argv[1], argv[2]));
}
