#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, size_t> hmap;
        size_t sz = nums.size();
        for (size_t i = 0; i < sz; ++i) {
            int sec = target - nums[i];
            hmap.emplace(nums[i], i);
            auto it = hmap.find(sec);
            if (it == hmap.end()) continue;
            if (it ->second == i) continue;
            return {int(it->second), int(i)};
        }
        return {};
    }
};

int main ()
{
    Solution s;
    //vector<int> input {8, 5, 9, 60, 30, 2, 7, 11, 15};
    vector<int> input {3, 2, 4};
    auto rst = s.twoSum(input, 6);
    if (rst.size()) {
        for (auto &&v : rst) {
            printf("%d ", v);
        }
        printf("\n");
    }
}
