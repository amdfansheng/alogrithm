#include "binary_tree.h"

using namespace std;

class Solution : public BinaryTree {
public:
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;
        return maxDepthIn(root);
    }

    int minDepthIn(TreeNode *node)
    {
        if (!node) return 0;

        int ld{}, rd{};
        if (node->left) ld = maxDepthIn(node->left);
        if (node->right) rd = maxDepthIn(node->right);

        return ld > rd ? ld + 1 : rd + 1;
    }
};

int main()
{
    //vector<int> nums = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    vector<int> nums = {1, 2, 3, 4, 5};

    Solution s;
    s.BuildTree(nums);
    s.BreadthFirstSearch();

    int depth = s.maxDepth(s.root());
    printf("depth: %d\n", depth);
}

