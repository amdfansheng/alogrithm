// n 个整数的无序数组，找到每个元素后面比它大的第一个数，要求时间复杂度为O(N)
#include <vector>
#include <stack>
#include <cstdio>
#include <climits>

using namespace std;

vector<int> findMax(const vector<int> &nums)
{
    size_t size = nums.size();
    if (size <= 1) return nums;

    vector<int> ret;
    ret.resize(size);

    stack<int> memo;
    int i {};
    while (i < nums.size()) { // 更优雅，为什么这种写法更简单呢？因为把i++ 从 for 中拿出来了，位置更灵活
        if (memo.empty() || nums[memo.top()] >= nums[i]) {
            memo.push(i++);
        } else {
            ret[memo.top()] = nums[i];
            memo.pop();
        }
    }

    while (memo.size()) {
        ret[memo.top()] = INT_MAX;
        memo.pop();
    }

    return ret;
}

void print(const vector<int> &nums)
{
    for (auto &&v : nums) {
        printf("%d ", v);
    }
    printf("\n");
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 0, 6, 2, 0, 1, 6, 0, 8, 2, 1, 0, 3, 2, 2};
    vector<int> ret (findMax(nums));

    print(nums);
    print(ret);
}
