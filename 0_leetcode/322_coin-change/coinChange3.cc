//  自顶向下， 备忘录的递归解法
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> memo(amount + 1, INT_MIN);
        return dp(memo, coins, amount);
    }

    int dp(vector<int> &memo, vector<int> &coins, int amount)
    {
        if (!amount) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != INT_MIN) return memo[amount];

        int min{INT_MAX};
        for (auto &&coin : coins) {
            //printf("amount: %d, coin: %d\n", amount, coin);
            int subpro = dp(memo, coins, amount - coin);
            //printf("subpro: %d\n", subpro);
            if (subpro == -1) continue;
            if (min > subpro + 1) min = subpro + 1;
        }
        //printf("amount: %d, min: %d\n", amount, min);
        memo[amount] = min == INT_MAX ? -1 : min;
        return memo[amount];
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
