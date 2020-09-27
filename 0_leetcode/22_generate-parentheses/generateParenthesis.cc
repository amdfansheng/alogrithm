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
        if (n == 0) return vector<string>();
        if (n == 1) return vector<string>{"()"};
        if (n == 2) return vector<string>{"(())", "()()"};




        return vector<string>();
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
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int n = atoi(argv[1]);
    Solution s;
    vector<string> ret = s.generateParenthesis(n);
    printf("n: %d\n", n);

    for (auto &&item : ret) {
        if (s.isValid(item)) printf("%s\n", item.data());
    }
}
