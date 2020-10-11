#include <vector>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        word_ = word;
        col_size_ = board[0].size();
        row_size_ = board.size();
        vector<char> memo;
        memo.resize(col_size_ * row_size_);
        for (int i = 0; i < row_size_; ++i) {
            for (int j = 0; j < col_size_; ++j) {
                //printf("%c: %c\n", word_[0], board[i][j]);
                if (board[i][j] != word_[0]) continue;
                memo[i * col_size_ + j] = 1;
                //printf("found: %c: %d %d\n", word_[0], i, j);
                if (back_trace(1, i, j, memo, board)) return true;
                memo[i * col_size_ + j] = 0;
            }
        }
        return false;
    }

    bool back_trace(int i, int row, int col, vector<char> &memo, vector<vector<char>> &board)
    {
        if (i == word_.size()) return true;

        vector<pair<int, int>> paths;
        if (row - 1 >= 0) paths.emplace_back(row - 1, col);
        if (row + 1 < row_size_) paths.emplace_back(row + 1, col);
        if (col - 1 >= 0) paths.emplace_back(row, col - 1);
        if (col + 1 < col_size_) paths.emplace_back(row, col + 1);

        for (auto &&point : paths) {
            //printf("char: %c: %d %d\n", word_[i], point.first, point.second);
            if (board[point.first][point.second] != word_[i]) continue;

            int index = point.first *  col_size_ + point.second;
            if (memo[index] == 1) continue;
            memo[index] = 1;
            if (back_trace(i + 1, point.first, point.second, memo, board)) return true;
            memo[index] = 0;
        }
        return false;
    }

    string word_;
    int col_size_ = 0;
    int row_size_ = 0;
};

int main()
{
    vector<vector<char>> board = {
          {'A','B','C','E'},
          {'S','F','C','S'},
          {'A','D','E','E'}
    };

    Solution s;
    bool r1 = s.exist(board, "ABCCED");
    printf("%s\n", r1 ? "true" : "false");
    bool r2 = s.exist(board, "SAD");
    printf("%s\n", r2 ? "true" : "false");
    bool r3 = s.exist(board, "ABCB");
    printf("%s\n", r3 ? "true" : "false");
}
