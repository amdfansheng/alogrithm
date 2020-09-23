//  自下向上，动态规划
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;

        for (int i = 1; i < amount + 1; ++i) {
            for (auto &&coin : coins) {
                if (i - coin < 0) continue;
                if (memo[i] > memo[i - coin] + 1) memo[i] = memo[i - coin] + 1;
            }
            printf("memo[%d]: %d\n", i, memo[i]);
        }
        return memo[amount] == amount + 1 ? -1 : memo[amount];
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
