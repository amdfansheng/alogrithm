// 自己写的
// DP
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 0 || triangle[0].size() == 0) return 0;

        size_t sz = triangle.size();
        size_t lsz = triangle[sz - 1].size();
        vector<vector<int>> memo;
        memo.resize(sz);
        for (auto &&vec : memo) {
            vec.resize(lsz);
        }

        dp(memo, triangle);
        return memo[0][0];
    }

    void dp(vector<vector<int>> &memo, const vector<vector<int>> &triangle)
    {
        // base case
        size_t lrow = memo.size() - 1;
        memo[lrow] = triangle[lrow];

        for (int row = lrow - 1; row >= 0; --row) {
            size_t sz = triangle[row].size();
            for (int col = 0; col < sz; ++col) {
                int c1 = triangle[row][col] + memo[row + 1][col];
                int c2 = triangle[row][col] + memo[row + 1][col + 1];
                memo[row][col] = c1 > c2 ? c2 : c1;
            }
        }
    }
};

int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    //vector<vector<int>> triangle = {
        //{-1},
        //{3, 2},
        //{-3, 1, -1}
    //};

    Solution s;
    printf("%d\n", s.minimumTotal(triangle));
}
