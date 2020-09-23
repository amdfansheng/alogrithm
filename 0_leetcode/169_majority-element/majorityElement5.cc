// 分治化, 最差的解法
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        if (nums.size() < 3) return nums[0];

        int cur{-1}, count{};
        for (auto &&num : nums) {
            if (count == 0) cur = num;
            num == cur ? ++count : --count;
        }

        return cur;
    }
};

int main()
{
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    //vector<int> v = {3, 2, 3};
    Solution s;
    printf("majority: %d\n", s.majorityElement(v));
}
