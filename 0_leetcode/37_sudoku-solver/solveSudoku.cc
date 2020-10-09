#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<int> memo(9, 0);
        build_memo(memo, board);
        back_trace(0, memo, board);
    }

    void build_memo(memo, board)
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

    void back_trace(int row, vector<int> &memo, vector<vector<char>> &board)
    {
        if (row == 9) return;

        for (int col = 0; col < 9; ++col) {
            int box = (row / 3) * 3 + col / 3; // key state
            if (board[row][col] != '.')  continue;

            for (int n = 0; n < 9; ++n) {
                if (!is_valid(row, col, box, num[n]), memo) continue;
                board[row][col] = num[n];
                back_trace(row + 1, memo, board);
                clear_memo();
            }
        }
    }

    bool is_valid(int r, int c, int b, char num, vector<int> &memo)
    {
        int index = num - '1'; // '1' -> 0
        int rmask = 0x1 << index, cmask = rmask << 9, bmask = cmask << 9;
        if ((memo[r] & rmask) != 0 || (memo[c] & cmask) != 0 || (memo[b] & bmask) != 0) return false;
        memo[r] |= rmask; memo[c] |= cmask; memo[b] |= bmask;
        return true;
    }

    void fill_memo(int r, int c, int b, char num, vector<int> &memo)
    {
        int index = num - '1'; // '1' -> 0
        memo[r] |= 0x1 << index;
        memo[c] |= 0x1 << index << 9;
        memo[b] |= 0x1 << index << 18;
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

    char num[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
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
    bool ret = s.is_valid_sudoku(board);
    printf("%s\n", ret ? "valid" : "not valid");

    s.dump(board);
    printf("%d\n", '5' - 48);
}
