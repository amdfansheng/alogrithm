// N 皇后问题
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        if (n < 3) return vector<vector<string>>();

        vector<pair<int, int>> trace; // <row, col>
        back_trace(n, 0, trace);
        return ret;
    }

    void back_trace(int n, int row, vector<pair<int, int>> &trace) // 路径，选择列表
    {
        if (row == n) {
            if (!is_valid(n, trace)) {
            }
            return;
        }

        for (int i = 0; i < n; ++i) {
            trace.emplace_back(pair<int, int>{row, i});
            back_trace(n, row + 1, trace);
            trace.erase(trace.end() - 1);
        }
    }

    bool is_valid(int n, const vector<pair<int, int>> &trace)
    {
        // 查列
        for () {
        }
    }

    vector<vector<string>> ret;
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int n = atoi(argv[1]);
    printf("n: %d\n", n);

    Solution s;
    vector<vector<string>> result = s.solveNQueens(n);
    for (auto &&vec : result) {
        for (auto &&s : vec) {
            printf("%s ", s.data());
        }
        printf("\n");
    }
}
