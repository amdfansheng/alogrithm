#include <cstdio>
#include <vector>

using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int> &nums)
    {
        size_t sz = nums.size();
        size_t max_pos{}, min_pos{};
        int max(0x80000000), min{}, ret(0x80000000), tmp{};
        for (size_t i = 0; i < sz; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                max_pos = i;
            }
            if (nums[i] < min) {
                min = nums[i];
                min_pos = i;
            }
        }
        printf("max: %d, pos: %zu\nmin: %d, pos: %zu\n", max, max_pos, min, min_pos);

        if (max_pos < min_pos) {
            for (size_t start = max_pos; start < min_pos; ++start) {
                tmp += nums[start];
                if (ret < tmp) ret = tmp;
                printf("max_pas < min_pos, back, tmp: %d, ret: %d\n", tmp, ret);
            }
            tmp = 0;
            for (size_t start = max_pos; start != -1; --start) {
                tmp += nums[start];
                if (ret < tmp) ret = tmp;
                printf("max_pas < min_pos, forward, tmp: %d, ret: %d\n", tmp, ret);
            }
        } else {
            for (size_t start = max_pos; start < sz; ++start) {
                tmp += nums[start];
                if (ret < tmp) ret = tmp;
                printf("max_pas >= min_pos, back, tmp: %d, ret: %d\n", tmp, ret);
            }
            tmp = 0;
            for (size_t start = max_pos; start != min_pos - 1; --start) {
                tmp += nums[start];
                if (ret < tmp) ret = tmp;
                printf("max_pas >= min_pos, forward, tmp: %d, ret: %d\n", tmp, ret);
            }
        }
        return ret;
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
