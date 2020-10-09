// N 皇后问题
// 自己写的，在 leetcode 上当 n = 8 会暴栈
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> trace; // [row 0, row 1, ... , row n - 1] 's column
        trace.resize(n);
        back_trace(n, 0, trace);
        return ret;
    }

    void back_trace(int n, int row, vector<int> &trace) // 路径，选择列表
    {
        if (row == n) {
            build_string(n, trace);
            return;
        }

        for (int col = 0; col < n; ++col) {
            trace[row] = col; // 回溯体现在这里
            if (!is_valid(n, row, col, trace)) continue; // 剪枝(验证)
            back_trace(n, row + 1, trace); // 这里不需要撤消选择，因为数组可以覆盖
        }
    }

    bool is_valid(int n, int row, int col, const vector<int> &trace)
    {
        int leftup = col - 1, rightup = col + 1;
        for (int r = row - 1; r >= 0; --r) {
            if (trace[r] == col) return false; // 同列
            if (leftup >= 0 && trace[r] == leftup) return false;  // 左上角线
            if (rightup <= n && trace[r] == rightup) return false; // 右上角线

            --leftup;
            ++rightup;
        }

        return true;
    }

    void build_string(int n, const vector<int> &trace)
    {
        vector<string> ans;
        string row; row.resize(n + 1);
        for (auto &&q : trace) {
            for (int c = 0; c < n; ++c) {
                if (c == q) row[c] = 'Q';
                else row[c] = '.';
            }
            ans.emplace_back(row);
        }
        ret.emplace_back(ans);
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
    int count{};
    for (auto &&vec : result) {
        printf("Solution %d:\n", count);
        for (auto &&s : vec) {
            printf("\t%s\n", s.data());
        }
        ++count;
    }
}
