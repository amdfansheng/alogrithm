#include <vector>
#include <cstdio>
#include <limits.h>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : array(k + 1, INT_MIN), cur_size(k)
    {
        if (nums.empty()) return;

        size_t sz{};
        k < nums.size() ? sz = k : sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            array[i + 1] = nums[i];
        }

        // build heap
        for (size_t i = cur_size / 2; i > 0; --i) {
            percolateDown(i);
        }

        if (cur_size > nums.size()) return;
        for (size_t i = cur_size; i < nums.size(); ++i) {
            if (array[1] > nums[i]) continue;
            array[1] = nums[i];
            percolateDown(1);
        }

        //for (int i = 0; i < cur_size; ++i) {
            //printf("%d ", array[i + 1]);
        //}
        //printf("\n");
    }

    int add(int val)
    {
        if (array[1] > val) return array[1];

        array[1] = val;
        percolateDown(1);

        return array[1];
    }

private:
    void percolateDown(size_t hole)
    {
        int x = array[hole];
        size_t child;
        for (; hole * 2 <= cur_size; hole = child) {
            child = hole * 2;
            if (child != cur_size && array[child + 1] < array[child]) // find child node
                ++child;

            if (array[child] < x)
                array[hole] = array[child];
            else
                break;
        }

        array[hole] = x;
    }

    vector<int> array;
    size_t cur_size = 0;
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
