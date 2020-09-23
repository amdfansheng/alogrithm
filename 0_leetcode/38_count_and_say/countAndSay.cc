#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    Solution()
    {
        expres.reserve(30);
        for (int i = 0; i < 31; ++i) {
            if (i == 1) expres.emplace_back("1");
            expres.emplace_back();
        }
    }

    string calcExpre(const string &pre)
    {
        string ret;
        ret.reserve(256);
        auto slow = pre.begin(), fast = slow;
        auto end = pre.end() + 1;
        for (; fast != end; ++fast) {
            //fprintf(stderr, "%c : %c\n", *slow, *fast);
            if (*slow == *fast) continue;
            auto dis = fast - slow;
            //fprintf(stderr, "distance: %zu\n", dis);
            ret.append(to_string(dis)).append(&*slow, 1);
            //fprintf(stderr, "%s\n", ret.data());
            slow = fast;
        }
        return ret;
    }

    string countAndSay(int n) {
        if (n < 1 || n > 30) return string();
        if (n == 1) return expres[1];

        if (!expres[n].size()) {
            string pre = countAndSay(n - 1);
            string ret = calcExpre(pre);
            expres[n] = std::move(ret);
        }
        return expres[n];
    }

    vector<string> expres;
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int n = atoi(argv[1]);

    Solution s;
    //for (auto &&v : s.expres) {
        //fprintf(stderr, "\"%s\", ", v.data());
    //}
    //fprintf(stderr, "\n");
    printf("%s\n", s.countAndSay(n).data());
    //printf("%s\n", s.calcExpre("111221").data());
}
