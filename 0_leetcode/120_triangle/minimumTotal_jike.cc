// 回溯算法
// 不可行，会超出时间限制
#include <vector>
#include <string>
#include <cstdio>
#include <climits>

using namespace std;

class Solution {
public:
    int min_ = INT_MAX;

    int minimumTotal(vector<vector<int>> &triangle)
    {
       if (triangle.size() == 0 || triangle[0].size() == 0) return 0;
       dfs(0, 0, 0, triangle, string());
       return min_;
    }

    void dfs(int row, int col, int sum, vector<vector<int>> &triangle, string path)
    {
        //printf("row: %d, col: %d, sum: %d\n", row, col, sum);
        if (row == triangle.size() - 1) {
            printf("%s\n", path.append(to_string(triangle[row][col])).data());
            sum += triangle[row][col];
            if (sum < min_) min_ = sum;
            return;
        }

        sum += triangle[row][col];
        path.append(to_string(triangle[row][col])).append(" -> ");

        dfs(row + 1, col, sum, triangle, path);
        dfs(row + 1, col + 1, sum, triangle, path);
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
