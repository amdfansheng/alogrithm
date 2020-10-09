#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {

    }

    bool isValidSudoku(vector<vector<char>> &board)
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
    bool ret = s.isValidSudoku(board);
    printf("%s\n", ret ? "valid" : "not valid");
}
