// 本题是一道非常经典且历史悠久的动态规划题，其作为算法题出现，最早可以追溯到 1994 年的 IOI（国际信息学奥林匹克竞赛）的 The Triangle。
// 时光飞逝，经过 20 多年的沉淀，往日的国际竞赛题如今已经变成了动态规划的入门必做题，不断督促着我们学习和巩固算法。
//
// 回溯算法
// 不可行，会超出时间限制
#include <vector>
#include <cstdio>
#include <climits>

using namespace std;

class Solution {
public:
    int min_ = INT_MAX;

    int minimumTotal(vector<vector<int>> &triangle)
    {
       if (triangle.size() == 0 || triangle[0].size() == 0) return 0;
       dfs(0, 0, 0, triangle);
       return min_;
    }

    void dfs(int row, int col, int sum, vector<vector<int>> &triangle)
    {
        printf("row: %d, col: %d, sum: %d\n", row, col, sum);
        if (row == triangle.size()) {
            if (sum < min_) min_ = sum;
            return;
        }

        for (int c = col; c < triangle[row].size(); ++c) {
            printf("row: %d, col: %d, c: %d\n", row, col, c);
            if (c > col + 1) return;

            sum += triangle[row][c];
            dfs(row + 1, c, sum, triangle);
            sum -= triangle[row][c];
        }
    }
};

int main()
{
    //vector<vector<int>> triangle = {
        //{2},
        //{3, 4},
        //{6, 5, 7},
        //{4, 1, 8, 3}
    //};

    vector<vector<int>> triangle = {
        {-1},
        {3, 2},
        {-3, 1, -1}
    };

    Solution s;
    printf("%d\n", s.minimumTotal(triangle));
}
