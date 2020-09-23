// 自己写的
// 超出时间限制 O(n^2)
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int max{}, min{INT_MAX};
        for (auto &&price : prices) {
            if (price - min > max) max = price - min;
            if (min > price) min = price;
        }

        return max;
    }
};

int main()
{
    //vector<int> v = {7,1,5,3,6,4};
    //vector<int> v = {1,2,3,4,5};
    //vector<int> v = {7,6,4,3,1};
    vector<int> v = {2,4,1};

    Solution s;
    printf("%d\n", s.maxProfit(v));
}
