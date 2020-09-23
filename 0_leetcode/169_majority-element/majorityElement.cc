// 哈希表
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // my method, stupid, not good
    //int majorityElement(vector<int>& nums)
    //{
        //unordered_map<int, int> times;
        //for (auto &&v : nums) {
            //if (times.find(v) == times.end())
                //times[v] = 1;
            //else
                //++times[v];
        //}

        //int ret{}, max_time{};
        //for (auto &&kv : times) {
            //if (kv.second > max_time) {
                //max_time = kv.second;
                //ret = kv.first;
            //}
        //}

        //return ret;
    //}

    //int majorityElement(vector<int>& nums)
    //{
        //unordered_map<int, int> times;
        //int ret{}, max_time{};
        //for (auto &&v : nums) {
            //++times[v];

            //if (times[v] > max_time) {
                //max_time = times[v];
                //ret = v;
            //}
        //}

        //return ret;
    //}

    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> times;
        for (auto &&v : nums) {
            ++times[v];

            if (times[v] > nums.size() / 2) return v;
        }

        return -1;
    }
};

int main()
{
    vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    //vector<int> v = {3, 2, 3};
    Solution s;
    printf("majority: %d\n", s.majorityElement(v));
}
