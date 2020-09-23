// 自己写的，无法通过[186,419,83,408] 2649测试用例
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(), coins.end(), greater<int>());
        int sz = coins.size();
        int res[sz];
        for (int i = 0; i < sz; ++i) {
            res[i] = 0;
        }
        for (int i = 0; i < sz; ++i) {
            find(coins, i, sz, amount, res[i]);
        }

        sort(res, res + sz);
        return res[0];
    }

    void find(vector<int> &coins, int start, int size, int remain, int &count)
    {
        printf("start: %d, value: %d, remain: %d, count: %d\n", start, coins[start], remain, count);
        if (!remain) return;
        if (start == size && remain > 0) {
            count = -1;
            return;
        }

        if (coins[start] <= remain) {
            ++count;
            find(coins, start, size, remain - coins[start], count);
        } else {
            find(coins, start + 1, size, remain, count);
        }
    }
};

int main(int argc, char *argv[])
{
    //vector<int> coins = {1, 2, 5};
    //vector<int> coins = {2};
    //vector<int> coins = {10, 9, 5, 1};
    vector<int> coins = {186, 419, 83, 408};

    Solution s;

    if (argc < 2) return -1;
    int amount = atoi(argv[1]);
    printf("%d coins number: %d\n", amount, s.coinChange(coins, amount));
}
