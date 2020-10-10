#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
private:
    int line[9];
    int column[9];
    int block[3][3];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    void flip(int i, int j, int digit) {
        line[i] ^= (1 << digit);
        column[j] ^= (1 << digit);
        block[i / 3][j / 3] ^= (1 << digit);
    }

    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        //auto [i, j] = spaces[pos]; // C++17语法, 结构化绑定声明 https://zh.cppreference.com/w/cpp/language/structured_binding
		auto point = spaces[pos];
		int i = point.first;
		int j = point.second;
        int mask = ~(line[i] | column[j] | block[i / 3][j / 3]) & 0x1ff;
        for (; mask && !valid; mask &= (mask - 1)) {
            int digitMask = mask & (-mask);
            int digit = __builtin_ctz(digitMask);
            flip(i, j, digit);
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            flip(i, j, digit);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, 0, sizeof(line));
        memset(column, 0, sizeof(column));
        memset(block, 0, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                }
                else {
                    int digit = board[i][j] - '0' - 1;
                    flip(i, j, digit);
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
