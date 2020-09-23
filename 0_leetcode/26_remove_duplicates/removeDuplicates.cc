#include <cstdio>
#include <vector>

using namespace std;

class Solution {
    public:
    int removeDuplicates2(vector<int>& nums) {
        int tag{};
        size_t sz = nums.size();
        for (size_t cursor = 0; cursor < sz; ++cursor) {
            if (nums[cursor] != nums[cursor + 1]) {
                continue;
            }
            tag = cursor + 1;
            size_t i = tag + 1;
            for (; i < sz; ++i) { if (nums[i] != nums[i + 1]) break; }
            nums[tag] = nums[i + 1];
            ++tag;

        }
        return --tag;
    }
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;

        auto slow = nums.begin();
        auto fast = nums.begin() + 1;
        for (; fast < nums.end(); ++fast) {
            if (*slow != *fast) {
                ++slow;
                *slow = *fast;
                continue;
            }

        }
        return (slow - nums.begin()) + 1;
    }

    //int seek_bigger()
};

void dump(const vector<int> &vec, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main()
{
    //vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    //vector<int> nums = {0,1,2,3,4};
    vector<int> nums = {};
    dump(nums, nums.size());

    Solution s;
    int len = s.removeDuplicates(nums);
    dump(nums, len);
}
