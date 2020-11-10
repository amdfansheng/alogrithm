// 全排列，经典回溯问题
// 回溯标准解决方法
#include <vector>
#include <cstdio>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int size = nums.size();
        if (size < 1) return vector<vector<int>>();
        if (size < 2) return vector<vector<int>>{nums};

        unordered_set<int> trace;
        back_trace(nums, trace);
        return ret;
    }

    void back_trace(vector<int> &nums, unordered_set<int> &trace) // 路径，选择列表
    {
        int size = nums.size();
        if (size == trace.size()) {
            vector<int> vec;
            for (auto &&v : trace) { vec.push_back(v); }
            ret.push_back(vec);
            return;
        }

        for (int i = 0; i < size; ++i) {
            auto it = trace.find(nums[i]);
            if (it != trace.end()) continue;

            auto it_pair = trace.emplace(nums[i]);
            back_trace(nums, trace);
            trace.erase(it_pair.first);
        }
    }

    vector<vector<int>> ret;
};

int main(int argc, char *argv[])
{
    //vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {1, 2, 3};

    Solution s;
    vector<vector<int>> result = s.permute(nums);
    for (auto &&vec : result) {
        for (auto &&v : vec) {
            printf("%d ", v);
        }
        printf("\n");
    }
}
