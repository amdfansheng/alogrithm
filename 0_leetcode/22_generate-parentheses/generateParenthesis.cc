#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        if (n <= 0) return vector<string>();
        if (n == 1) return vector<string>{"()"};
        if (n == 2) return vector<string>{"(())", "()()"};

        string str; str.resize(2 * n);
        str[0] = '('; str[2 * n - 1] = ')';

        gen_pare_in(str.data(), 2 * n, 0, 0, 1);
        return ret;
    }

    void gen_pare_in(string s, int size, int ln, int rn, int ind)
    {
        if (ind == size) {
            if (isValid(s)) ret.push_back(s);
            return;
        }
        if (ln == size / 2 || rn == size / 2) return;

        s[ind] = '(';
        gen_pare_in(s.data(), size, ln + 1, rn, ind + 1);
        s[ind] = ')';
        gen_pare_in(s.data(), size, ln, rn + 1, ind + 1);
    }

	bool isValid(const string & str)
    {
        size_t sz = str.size();
        if (!sz) return false;

        stack<char> bucket;
        for (size_t i = 0; i < sz; ++i) {
            if (bucket.size() && bucket.top() == '(' && str[i] == ')') {
                bucket.pop();
                continue;
            }
            bucket.push(str[i]);
        }

        if (bucket.empty()) return true;
        return false;
    }

    vector<string> ret;
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int n = atoi(argv[1]);
    Solution s;
    vector<string> ret = s.generateParenthesis(n);
    printf("n: %d\n", n);

    for (auto &&item : ret) {
        printf("%s\n", item.data());
    }
}
