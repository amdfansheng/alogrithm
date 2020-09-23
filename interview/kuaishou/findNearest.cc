#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int findNearest(const vector<double> &nums, double target)
{
    if (nums.empty()) return -1;

    int right{}, left = nums.size();
    if (target < nums[right]) return 0;
    if (target > nums[left - 1]) return left - 1;

    while (right + 1 < left) {
        int mid = right + left >> 1;
        if (target > nums[mid]) right = mid;
        if (target < nums[mid]) left = mid;
    }

    return target - nums[right] > nums[left] - target ? left : right;
}

int main(int argc, char *argv[])
{
    //vector<double> vec = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5};
    vector<double> vec = {};
    for (auto &&v : vec) printf("%f ", v);
    printf("\n");
    double target = atof(argv[1]);
    printf("%f nearest: %f\n", target, vec[findNearest(vec, target)]);
}
