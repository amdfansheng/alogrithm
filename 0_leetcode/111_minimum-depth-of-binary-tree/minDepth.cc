#include <algorithm>

#include "binary_tree.h"

using namespace std;

class Solution : public BinaryTree {
public:
	// 自己写的，很丑
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;

        minDepthIn(root, 1);

        sort(memo.begin(), memo.end());
        return memo[0];
    }

    void minDepthIn(TreeNode *node, int dep)
    {
        if (!node) return;

        if (!node->left && !node->right) {
            memo.push_back(dep);
            return;
        }

        minDepthIn(node->left, dep + 1);
        minDepthIn(node->right, dep + 1);
    }

    vector<int> memo;
};

int main()
{
    //vector<int> nums = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    vector<int> nums = {1, 2, 3, 4, 5};

    Solution s;
    s.BuildTree(nums);
    s.BreadthFirstSearch();

    int depth = s.minDepth(s.root());
    printf("depth: %d\n", depth);
}

