#include <vector>
#include <queue>
#include <cstdio>
#include <limits.h>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : size(k)
    {
        for (auto &&v : nums) {
            add(v);
        }
    }

    int add(int val)
    {
        if (size > array.size()) {
            array.push(val);
        } else if (array.top() < val) {
            array.pop();
            array.push(val);
        }

        return array.top();
    }

private:
    int size;
    priority_queue<int, vector<int>, greater<int>> array;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */





int main()
{
    vector<int> nums = {0};
    KthLargest* obj = new KthLargest(2, nums);
    printf("%d \n", obj->add(-1));
    printf("%d \n", obj->add(1));
    printf("%d \n", obj->add(-2));
    printf("%d \n", obj->add(-4));
    printf("%d \n", obj->add(3));
}
