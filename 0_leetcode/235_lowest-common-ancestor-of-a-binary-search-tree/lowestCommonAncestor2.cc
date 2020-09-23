#include "binary_tree.h"
#include <cstdlib>

using namespace std;

class Solution : public BinaryTree {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || !p || !q) return nullptr;

        while (root) {
            if (root->val > p->val &&
                root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val &&
                       root->val < q->val) {
                root = root->right;
            } else return root;
        }
        return nullptr;
    }

    TreeNode *find(TreeNode *start, int target)
    {
        if (!start) return nullptr;

        if (start->val > target) return find(start->left, target);
        else if (start->val < target) return find(start->right, target);
        else return start;
    }

    TreeNode *findMin(TreeNode *node) const
    {
        if (!node) return nullptr;

        if (!node->left) return node; // find, return

        return findMin(node->left); // not find, continue;
    }

    TreeNode *findMax(TreeNode *node)
    {
        if (!node) return nullptr;

        while (node->right) {
            node = node->right;
        }

        return node;
    }
};

int main(int argc, char *argv[])
{
    //vector<int> vec = {5,1,4,INT_MAX,INT_MAX,3,6};
    vector<int> vec = {6,2,8,0,4,7,9,INT_MAX,INT_MAX,3,5};

    Solution t;
    t.BuildTree(vec);
    //t.PrePrint();
    //t.InPrint();
    //t.PostPrint();
    //t.DepthFirstSearch();
    t.BreadthFirstSearch();
    //t.InPrintNoRecursion();
    printf("min: %d\n", t.findMin(t.root())->val);
    printf("max: %d\n", t.findMax(t.root())->val);
    if (argc < 3) return -1;
    //int target = atoi(argv[1]);
    //if (t.find(t.root(), target)) printf("find %d\n", target);
    //else printf("not find: %d\n", target);
    int leftval = atoi(argv[1]);
    int rightval = atoi(argv[2]);
    BinaryTree::TreeNode *left = t.find(t.root(), leftval);
    printf("left: %d\n", left->val);
    BinaryTree::TreeNode *right = t.find(t.root(), rightval);
    printf("right: %d\n", right->val);
    BinaryTree::TreeNode *ancestor = t.lowestCommonAncestor(t.root(), left, right);
    if (ancestor)
        printf("ancestor of %d and %d: %d\n", leftval, rightval, ancestor->val);
    else
        printf("ancestor of %d and %d: not found\n", leftval, rightval);
}
