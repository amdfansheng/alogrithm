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
        vector<pair<int, int>> trace; // <row, col>
        back_trace(n, 0, trace);
        return ret;
    }

    void back_trace(int n, int row, vector<pair<int, int>> &trace) // 路径，选择列表
    {
        if (row == n) {
            if (is_valid(n, trace)) build_string(n, trace);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // 剪枝
            size_t size = trace.size();
            if (size) {
                int lcol = trace[size - 1].second;
                if (lcol - 1 == col || lcol == col || lcol + 1 == col) continue;
            }

            trace.emplace_back(pair<int, int>{row, col});
            back_trace(n, row + 1, trace);
            trace.erase(trace.end() - 1);
        }
    }

    bool is_valid(int n, const vector<pair<int, int>> &trace)
    {
        vector<int> memo;
        memo.resize(n * 10);
        for (auto &&p : trace) {
            if (memo[p.first * 10 + p.second] > 0) return false;
            build_fliter(memo, p, n);
        }
        return true;
    }

    void build_fliter(vector<int> &memo, const pair<int, int> &point, int n)
    {
        // 同列
        for (int row = point.first + 1, col = point.second; row < n; ++row) {
            memo[row * 10 + col] = row * 10 + col;
        }
        // 左上
        for (int row = point.first - 1, col = point.second - 1; row >= 0 && col >= 0; --row, --col) {
            memo[row * 10 + col] = row * 10 + col;
        }
        // 右上
        for (int row = point.first - 1, col = point.second + 1; row >= 0 && col < n; --row, ++col) {
            memo[row * 10 + col] = row * 10 + col;
        }
        // 右下
        for (int row = point.first + 1, col = point.second + 1; row < n && col < n; ++row, ++col) {
            memo[row * 10 + col] = row * 10 + col;
        }
        // 左下
        for (int row = point.first + 1, col = point.second - 1; row < n && col >= 0; ++row, --col) {
            memo[row * 10 + col] = row * 10 + col;
        }
    }

    void build_string(int n, const vector<pair<int, int>> &trace)
    {
        vector<string> ans;
        char row[n + 1] = {0};
        for (auto &&p : trace) {
            for (int i = 0; i < n; ++i) {
                if (i == p.second) row[i] = 'Q';
                else row[i] = '.';
            }
            ans.emplace_back((const char *)row);
        }
        ret.emplace_back(ans);
    }

    void print_trace(const vector<pair<int, int>> &trace)
    {
        for (auto &&p : trace) {
            printf("{%d %d} ", p.first, p.second);
        }
        printf("\n");
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
