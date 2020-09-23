// 排序法
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main()
{
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    //vector<int> v = {3, 2, 3};
    Solution s;
    printf("majority: %d\n", s.majorityElement(v));
}
