#include <string>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> window;

        int left{}, right{}, res{};
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            while (window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    Solution s;
    auto res = s.lengthOfLongestSubstring(argv[1]);
    printf("%d\n", res);
}
