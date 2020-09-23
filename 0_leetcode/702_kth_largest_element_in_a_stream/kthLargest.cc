#include <cstdio>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : array(k + 1), cur_size(k)
    {
        for (int i = 0; i < cur_size; ++i) {
            array[i + 1] = nums[i];
        }

        // build heap
        for (size_t i = cur_size / 2; i > 0; --i) {
            percolateDown(i);
        }

        size_t sz = nums.size();
        if (cur_size > sz) return;
        for (size_t i = cur_size; i < sz; ++i) {
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



int main()
{
    vector<int> nums = {4, 8, 5, 2};
    printf("vector size: %zu\n", nums.size());

    KthLargest* obj = new KthLargest(3, nums);

    printf("%d\n", obj->add(3));
    printf("%d\n", obj->add(5));
    printf("%d\n", obj->add(10));
    printf("%d\n", obj->add(9));
    printf("%d\n", obj->add(4));
}
