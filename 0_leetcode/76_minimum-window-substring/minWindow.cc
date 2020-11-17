#include <cstdio>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> window, need; // window 滑动窗口内字符个数计数
        for (auto &&c : t) need[c]++;

        int s_sz = s.size(), n_sz = need.size();
        int left{}, right{}, valid{}, start{}, len{INT_MAX}; // valid 满足数量要求的字符数
        while (right < s_sz) {
            char c = s[right]; // c 是将移入窗口的字符
            right++; // 右移窗口
            if (need.count(c)) { // 进行窗口内数据的一系列更新, 下面两行顺序不能错
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            printf("window: [%d, %d)\n", left, right);
            while (valid == n_sz) { // 判断左侧窗口是否要收缩
                if (right - left < len) { // 在这里更新最小覆盖子串
                    start = left;
                    len = right - left;
                }

                char d = s[left]; // d 是将移出窗口的字符
                left++; // 左移窗口
                if (need.count(d)) { // 进行窗口内数据的一系列更新, 下面两行顺序不能错
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? string() : s.substr(start, len); // 返回最小覆盖子串
    }
};

int main(int argc, char *argv[])
{
    if (argc < 3) return -1;

    Solution s;
    auto res = s.minWindow(argv[1], argv[2]);
    printf("%s\n", res.data());
}
