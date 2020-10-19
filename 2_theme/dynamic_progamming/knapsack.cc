#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

// 对于一组不同重量、不可分割的物品，我们需要选择一些装入背包，
// 在满足背包最大重量限制的前提下，背包中物品总重量的最大值是多少呢？
int knapsack1(const vector<int> &items, int items_size, int w)
{
    vector<bool> states; states.resize(w + 1);

    // base case
    states[0] = true;
    if (items[0] <= w) states[items[0]] = true;

    for (int i = 1; i < items_size; ++i) { // 动态规划
        for (int j = w - items[i]; j >= 0; --j) {   //把第i个物品放入背包, 从 w - items[i] 开始，因为 w - items[i] 之后的肯定大于 w 了
        //for (int j = 0; j < w; ++j) {   // 不能从前往后算，这样会产生重复计算
	    if (states[j] == true) states[j + items[i]] = true;
	}
     }

     for (int i = w; i >= 0; --i) { // 输出结果
         if (states[i] == true) return i;
     }
     return 0;
}

// 对于一组不同重量、不同价值、不可分割的物品，我们选择将某些物品装入背包，
// 在满足背包最大重量限制的前提下，背包中可装入物品的总价值最大是多少呢？
int knapsack2(const vector<int> &items, const vector<int> &vals, int n, int w)
{
    vector<int> states(w + 1, -1);

    // base case
    states[0] = 0;
    if (items[0] <= w) states[items[0]] = vals[0];

    for (int i = 1; i < n; ++i) { // 动态规划
    	for (int j = w - items[i]; j >= 0; --j) {   //把第i个物品放入背包
            if (states[j] < 0) continue;

            int new_wei = j + items[i];
            int new_val = states[j] + vals[i];
            if (new_val > states[new_wei]) states[new_wei] = new_val;
	}
   }

   int max_val = -1;
   for (int i = w; i >= 0; --i) { // 输出结果
       if (states[i] > max_val) max_val = states[i];
   }
   return max_val;
}

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int knapsack_weight = atoi(argv[1]);

    vector<int> nums = {2, 2, 4, 6, 3};
    int res1 = knapsack1(nums, nums.size(), knapsack_weight); // 16 出 15
    printf("max weight: %d\n", res1);

    vector<int> vals = {3, 4, 8, 9, 6};
    int res2 = knapsack2(nums, vals, nums.size(), knapsack_weight); // 16 出 27
    printf("max value: %d\n", res2);
}
