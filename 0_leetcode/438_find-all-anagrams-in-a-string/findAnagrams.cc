#include <string>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> window, need;
        for (auto &&c : p) need[c]++;

        vector<int> res;
        int left{}, right{}, valid{};
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (right - left == p.size()) {
                if (valid == need.size()) res.push_back(left);
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 3) return -1;
    Solution s;
    auto res = s.findAnagrams(argv[1], argv[2]);
    for (auto &&v : res) {
        printf("%d ", v);
    }
    printf("\n");
}
