// 简单的解决方案是遍历该 9 x 9 数独三次
// 内存消耗： 18.5 MB, 在所有 C++ 提交中击败了 5.04% 的用户
// 执行用时： 44 ms, 在所有 C++ 提交中击败了 6.03% 的用户
#include <cstdio>
#include <cstdlib>
//#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> memo; memo.reserve(9);
        // row
        for (int r = 0; r < 9; ++r) {
            for (auto &&c : board[r]) {
                if (c == '.') continue;
                if (memo.find(c) != memo.end()) return false;
                memo.insert(c);
            }
            memo.clear();
        }

        // column
        for (int c = 0; c < 9; ++c) {
            for (auto &&r : board) {
                if (r[c] == '.') continue;
                if (memo.find(r[c]) != memo.end()) return false;
                memo.insert(r[c]);
            }
            memo.clear();
        }

        // box
        for (int r = 0; r < 8; r += 3) {
            for (int c = 0; c < 8; c += 3) {
                int redge = r + 3;
                int cedge = c + 3;
                for (int ri = r; ri < redge; ++ri) {
                    for (int ci = c; ci < cedge; ++ci) {
                        char num = board[ri][ci];
                        //printf("%c ", num);
                        if (num == '.') continue;
                        if (memo.find(num) != memo.end()) return false;
                        memo.insert(num);
                    }
                    //printf("\n");
                }
                memo.clear();
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
