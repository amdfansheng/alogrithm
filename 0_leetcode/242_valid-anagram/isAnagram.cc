#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

// anagram: 相同字母异序词，易位构词，变位词
class Solution {
public:
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    bzero(compare, 256);

    int sour{}, dest{};
    for (auto &&c : s) {
        compare[(int)c] = (int)c;
        sour += (int)c;
    }

    for (auto &&c : t) {
        dest += (int)compare[(int)c];
    }

    return sour == dest;
}

private:
    char compare[256];
};

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("%s word1 word2", argv[0]);
        return -1;
    }
    Solution s;

    if (s.isAnagram(argv[1], argv[2]))
        printf("yes\n");
    else
        printf("no\n");
}
