#include "binary_tree.h"

using namespace std;

class Solution : public BinaryTree {
public:
    bool isValidBST(TreeNode* root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode *node, long long lower, long long upper)
    {
        if (!node) return true;

        if (node->val <= lower ||
            node->val >= upper) return false;

        if (!helper(node->left, lower, node->val)) return false;
        if (!helper(node->right, node->val, upper)) return false;

        return true;
    }
};

int main()
{
    //vector<int> vec = {5,1,4,INT_MAX,INT_MAX,3,6};
    //vector<int> vec = {2,1,3};
    //vector<int> vec = {1,1};
    vector<int> vec = {2,1,4,7,4,8,3,6,4,7};

    Solution t;
    t.BuildTree(vec);
    t.PrePrint();
    //t.InPrint();
    //t.PostPrint();

    if (t.isValidBST(t.root()))
        printf("valid BST.\n");
    else
        printf("invalid BST.\n");
}
