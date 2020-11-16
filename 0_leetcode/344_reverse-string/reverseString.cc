#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    // 左右指针
    void reverseString(vector<char> &s)
    {
        int left{}, right = s.size() - 1;
        while (left < right) {
            auto tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    vector<char> str;
    for (int i = 0; i < strlen(argv[1]); ++i) {
        str.emplace_back(argv[1][i]);
    }

    Solution s;
    s.reverseString(str);

    for (auto &&c : str) {
        printf("%c ", c);
    }
    printf("\n");
}
