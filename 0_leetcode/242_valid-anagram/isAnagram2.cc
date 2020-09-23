#include <string>
#include <cstdio>

using namespace std;

// anagram: 相同字母异序词，易位构词，变位词
class Solution {
public:
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    int hash[26] = {0};

    for (auto &&c : s) { ++hash[c - 'a']; }

    for (auto &&c : t) {
        if (--hash[c - 'a'] == -1) return false;
    }

    return true;
}
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
