// 暴力解法， 超出时间限制
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount < 0) return -1;
        if (!amount) return 0;

        int min{INT_MAX};
        for (auto &&coin : coins) {
            //printf("amount: %d, coin: %d, min: %d\n", amount, coin, min);
            int subpro = coinChange(coins, amount - coin);
            //printf("subpro: %d, min: %d\n", subpro, min);
            if (subpro == -1) continue;
            if (min > subpro + 1) min = subpro + 1;
        }
        //printf("amount: %d, min: %d\n", amount, min);
        return min == INT_MAX ? -1 : min;
    }
};

int main(int argc, char *argv[])
{
    vector<int> coins = {1, 2, 5};
    //vector<int> coins = {2};
    //vector<int> coins = {10, 9, 5, 1};
    //vector<int> coins = {186, 419, 83, 408};

    Solution s;

    if (argc < 2) return -1;
    int amount = atoi(argv[1]);
    printf("%d coins number: %d\n", amount, s.coinChange(coins, amount));
}
