// 自己写的
// 峰谷法
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int sz = prices.size() - 1;
        int sum{};
        for (int i = 0; i < sz; ++i) {
            if (prices[i] >= prices[i + 1]) continue;
            int y = i;
            for (; y < sz; ++y) {
                if (prices[y] < prices[y + 1]) continue;
                break;
            }
            sum += prices[y] - prices[i];
            i = y;
        }

        return sum;
    }
};

int main()
{
    //vector<int> v = {7,1,5,3,6,4};
    //vector<int> v = {1,2,3,4,5};
    vector<int> v = {7,6,4,3,1};

    Solution s;
    printf("%d\n", s.maxProfit(v));
}
