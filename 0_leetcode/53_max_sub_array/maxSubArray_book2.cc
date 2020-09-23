// 执行用时： 660 ms , 在所有 C++ 提交中击败了 5.10% 的用户
// 内存消耗： 6.9 MB , 在所有 C++ 提交中击败了 82.01% 的用户
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int> &nums)
    {
        int sum(0x80000000);
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            int thisSum{};
            for (int j = i; j < sz; ++j) {
                thisSum += nums[j];
                if (thisSum > sum) sum = thisSum;
            }
        }
        return sum;
    }
};

void dump(const vector<int> &vec)
{
    for (auto &&v : vec) {
        printf("%d ", v);
    }
    printf("\n");
}

int main()
{
    vector<vector<int>> vecs;
    vecs.emplace_back(vector<int>{-2,1,-3,4,-1,2,1,-5,4,4});
    vecs.emplace_back(vector<int>{-2,11,-4,13,-5,-2});
    vecs.emplace_back(vector<int>{0, 0, 0, 0});
    vecs.emplace_back(vector<int>{1, 2});
    vecs.emplace_back(vector<int>{2, 1});
    vecs.emplace_back(vector<int>{-2, -3, -1, -5});
    vecs.emplace_back(vector<int>{2, -1, 1, 1});

    Solution s;
    for (auto &&vec : vecs) {
        dump(vec);
        fprintf(stderr, "%d\n", s.maxSubArray(vec));
    }
}
