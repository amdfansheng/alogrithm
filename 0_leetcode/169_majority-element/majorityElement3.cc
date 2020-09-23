// 随机化
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        while (true) {
            int any = nums[rand() % nums.size()];
            int count{};
            for (auto &&v : nums) {
                if (v == any) ++count;
            }

            if (count > nums.size() / 2) return any;
        }

        return -1;
    }
};

int main()
{
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    //vector<int> v = {3, 2, 3};
    Solution s;
    printf("majority: %d\n", s.majorityElement(v));
}
