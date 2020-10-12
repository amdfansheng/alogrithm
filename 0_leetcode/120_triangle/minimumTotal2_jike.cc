// 极客时间，直接在给定的三角形数组上进行状态转移，不使用额外的空间。
// DP
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 0 || triangle[0].size() == 0) return 0;

        dp(triangle);
        return triangle[0][0];
    }

    void dp(vector<vector<int>> &triangle)
    {
        for (int row = triangle.size() - 2; row >= 0; --row) {
            size_t sz = triangle[row].size();
            for (int col = 0; col < sz; ++col) {
                int c1 = triangle[row][col] + triangle[row + 1][col];
                int c2 = triangle[row][col] + triangle[row + 1][col + 1];
                triangle[row][col] = c1 > c2 ? c2 : c1;
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
