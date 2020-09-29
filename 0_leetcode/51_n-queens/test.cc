//#include <unordered_set>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3) return -1;

    pair<int, int> point {atoi(argv[1]), atoi(argv[2])};
    printf("{%d %d}\n", point.first, point.second);

    int n = 4;
    vector<int> memo;
    memo.resize(n * 10);

    // 左上
    for (int row = point.first - 1, col = point.second - 1; row >= 0 && col >= 0; --row, --col) {
        memo[row * 10 + col] = row * 10 + col;
    }
    // 右上
    for (int row = point.first - 1, col = point.second + 1; row >= 0 && col < n; --row, ++col) {
        memo[row * 10 + col] = row * 10 + col;
    }
    // 右下
    for (int row = point.first + 1, col = point.second + 1; row < n && col < n; ++row, ++col) {
        memo[row * 10 + col] = row * 10 + col;
    }
    // 左下
    for (int row = point.first + 1, col = point.second - 1; row < n && col >= 0; ++row, --col) {
        memo[row * 10 + col] = row * 10 + col;
    }

    for (auto &&v : memo) {
        if (v == 0) continue;
        printf("{%d %d} ", v / 10, v % 10);
    }
    printf("\n");
}
