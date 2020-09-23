// 自己写的
// 超出时间限制 O(n^2)
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int sz = prices.size();
        if (!sz) return 0;

        int sum{};
        for (int i = 0; i < sz; ++i) {
            int max{};
            for (int y = i + 1; y < sz; ++y) {
                if (prices[y] - prices[i] > max)
                    max = prices[y] - prices[i];
            }
            if (max > sum) sum = max;
        }

        return sum;
    }
};

int main()
{
    //vector<int> v = {7,1,5,3,6,4};
    vector<int> v = {1,2,3,4,5};
    //vector<int> v = {7,6,4,3,1};
    //vector<int> v = {2,4,1};

    Solution s;
    printf("%d\n", s.maxProfit(v));
}
