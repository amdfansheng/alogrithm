#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<int> memo(9, 0);
        build_memo(memo, board);
        back_trace(0, 0, memo, board);
    }

    void build_memo(vector<int> &memo, vector<vector<char>> &board)
    {
        int rmask{}, cmask{}, bmask{};
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int index = board[r][c] - '1'; // '1' -> 0
                int b = (r / 3) * 3 + c / 3; // key state

                rmask = 0x1 << index; cmask = rmask << 9; bmask = cmask << 9;
                memo[r] |= rmask; memo[c] |= cmask; memo[b] |= bmask;
            }
        }
    }

    bool back_trace(int row, int col, vector<int> &memo, vector<vector<char>> &board)
    {
        // 找到一个可行解，触发 base case
        if (row == 9) return true;

        // 穷举到最后一列的话就换到下一行重新开始。必须在预设判断的前面
        if (col == 9) {
            return back_trace(row + 1, 0, memo, board);
        }

        // 如果有预设数字，不用我们穷举
        if (board[row][col] != '.') {
            return back_trace(row, col + 1, memo, board);
        }

        int box = (row / 3) * 3 + col / 3; // key state

        for (char ch = '1'; ch <= '9'; ++ch) {
            //printf("row: %d, col: %d, try: %c \n", row, col, ch);
            // 如果遇到不合法的数字，就跳过
            if (!is_valid(row, col, box, ch, memo)) continue;
            board[row][col] = ch;
            //printf("row: %d, col: %d, choice: %c \n", row, col, ch);
            // 如果找到一个可行解，立即结束
            if (back_trace(row, col + 1, memo, board)) return true;
            board[row][col] = '.';
            clear_memo(row, col, box, ch, memo);
            //printf("row: %d, col: %d, back: %c \n", row, col, ch);
        }
        // 穷举完 1~9，依然没有找到可行解，此路不通
        return false;
    }

    bool is_valid(int r, int c, int b, char num, vector<int> &memo)
    {
        int index = num - '1'; // '1' -> 0
        int rmask = 0x1 << index, cmask = rmask << 9, bmask = cmask << 9;
        if (memo[r] & rmask || memo[c] & cmask || memo[b] & bmask) return false;
        memo[r] |= rmask; memo[c] |= cmask; memo[b] |= bmask;
        return true;
    }

    void clear_memo(int r, int c, int b, char num, vector<int> &memo)
    {
        int index = num - '1'; // '1' -> 0
        int rmask = 0x1 << index, cmask = rmask << 9, bmask = cmask << 9;
        memo[r] &= ~rmask; memo[c] &= ~cmask; memo[b] &= ~bmask;
    }

    bool is_valid_sudoku(vector<vector<char>> &board)
    {
        vector<int> memo(9, 0);
        int rmask{}, cmask{}, bmask{};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int index = board[r][c] - '1'; // '1' -> 0
                int b = (r / 3) * 3 + c / 3; // key state

                rmask = 0x1 << index; cmask = rmask << 9; bmask = cmask << 9;
                if ((memo[r] & rmask) != 0 || (memo[c] & cmask) != 0 || (memo[b] & bmask) != 0) return false;
                memo[r] |= rmask; memo[c] |= cmask; memo[b] |= bmask;
            }
        }

        return true;
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
    //bool ret = s.is_valid_sudoku(board);
    //printf("%s\n", ret ? "valid" : "not valid");

    s.solveSudoku(board);
    s.dump(board);
}
