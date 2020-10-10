#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int, int>> spaces; // 预处理，用VECTOR保存所有空格位置，简化换行操作

public:
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        //auto [i, j] = spaces[pos]; // C++17语法, 结构化绑定声明 https://zh.cppreference.com/w/cpp/language/structured_binding
		auto point = spaces[pos];
		int i = point.first;
		int j = point.second;
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                dfs(board, pos + 1);
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                } else {
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }

        dfs(board, 0);
    }

    void dump(vector<vector<char>> &board)
    {
        for (auto &&row : board) {
            for (auto &&col : row) {
                printf("%c ", col);
            }
            printf("\n");
        }
    }

};

int main()
{
    vector<vector<char>> board = {
      {'5','3','.','.','7','.','.','.','.'},
      {'6','.','.','1','9','5','.','.','.'},
      {'.','9','8','.','.','.','.','6','.'},
      {'8','.','.','.','6','.','.','.','3'},
      {'4','.','.','8','.','3','.','.','1'},
      {'7','.','.','.','2','.','.','.','6'},
      {'.','6','.','.','.','.','2','8','.'},
      {'.','.','.','4','1','9','.','.','5'},
      {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;

    s.solveSudoku(board);
	s.dump(board);
}
