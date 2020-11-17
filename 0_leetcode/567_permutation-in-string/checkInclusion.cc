#include <string>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> window, need;
        for (auto &&c : s1) need[c]++;

        int left{}, right{}, valid{};
        int s1_sz = s1.size(), s2_sz = s2.size(), need_sz = need.size();
        while (right < s2_sz) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (right - left == s1_sz) {
                if (valid == need_sz) return true;
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 3) return -1;
    Solution s;
    printf("%s\n", s.checkInclusion(argv[1], argv[2]) ? "yes" : "no");
}
