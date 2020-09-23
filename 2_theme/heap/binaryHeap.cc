#include <cstdio>
#include <vector>

using namespace std;

class BinaryHeap {
public:
    explicit BinaryHeap(size_t capacity = 100) { array.resize(capacity); }
    explicit BinaryHeap(const vector<int> &nums) : array(nums.size() + 10), cur_size(nums.size())
    {
        for (size_t i = 0; i < cur_size; ++i) {
            array[i + 1] = nums[i];
        }
        buildHeap();
    }

    bool isEmpty() const { return array.empty(); }
    int findMin() const { return array[0]; }

    void insert(int x)
    {
        if (cur_size == array.size() - 1) array.resize(cur_size * 2);

        size_t hole = ++cur_size;
        for (; hole > 1 && x < array[hole / 2]; hole /= 2) { // hole up
            array[hole] = array[hole / 2];
        }
        array[hole] = x;
    }

    int deleteMin()
    {
        if (isEmpty()) return 0;

        int ret = array[1];
        printf("deleteMin() last item: %d\n", array[cur_size]);
        array[1] = array[cur_size--];
        printf("deleteMin() size: %zu\n", cur_size);

        percolateDown(1);

        return ret;
    }

    void makeEmpty()
    {
        vector<int> tmp;
        tmp.resize(100);
        array.swap(tmp);
    }

    size_t size()
    {
        return cur_size;
    }

private:
    void buildHeap()
    {
        for (size_t i = cur_size / 2; i > 0; --i) {
            percolateDown(i);
        }

        for (auto &&v : array) {
            printf("%d ", v);
        }
        printf("\n");
    }

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
    vector<int> v = {24, 65, 26, 31, 32, 21, 16, 19, 68, 13};
    printf("vector size: %zu\n", v.size());

    BinaryHeap bh(v);
    printf("binary heap size: %zu\n", bh.size());

    bh.insert(14);

    printf("min: %d\n", bh.deleteMin());
    printf("size: %zu\n", bh.size());
    printf("min: %d\n", bh.deleteMin());
}
