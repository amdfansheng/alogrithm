// 遍历 9 x 9 数独一次的解法，空间换时间的解决思路
// 1 个一维数组
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
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
                if (memo[r] & rmask || memo[c] & cmask || memo[b] & bmask) return false;
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
