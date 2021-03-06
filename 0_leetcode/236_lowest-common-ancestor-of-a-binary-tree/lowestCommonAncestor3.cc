// 存储父节点
// 执行用时：  44 ms , 在所有 C++ 提交中击败了  11.55%  的用户
#include "binary_tree.h"
#include <cstdlib>

using namespace std;

class Solution : public BinaryTree {
public:
    TreeNode *ans;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || !p || !q) return nullptr;

        dfs(root, p, q);
        return ans;
    }

    // 符合条件的最近公共祖先 x 一定满足如下条件：
    // (f_lson  && f_rson) ∣∣ ((x = p ∣∣ x = q) && (f_lson || f_rson))
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root) return false;

        bool lret = dfs(root->left, p, q);
        bool rret = dfs(root->right, p, q);

        if ((lret && rret) ||
            ((root->val == p->val || root->val == q->val) &&  (lret || rret)))
            ans = root;

        return lret || rret || (root->val == p->val || root->val == q->val);
    }

    TreeNode *find(TreeNode *start, int target)
    {
        if (!start) return nullptr;

        printf("target: %d, current val: %d\n", target, start->val);
        if (start->val == target) return start;
        TreeNode *ret;
        if (ret = find(start->left, target)) return ret;
        if (ret = find(start->right, target)) return ret;
    }

};

int main(int argc, char *argv[])
{
    vector<int> vec = {3,5,1,6,2,0,8,INT_MAX,INT_MAX,7,4};
    //vector<int> vec = {1,2,3};

    Solution t;
    t.BuildTree(vec);
    //t.PrePrint();
    //t.InPrint();
    //t.PostPrint();
    t.DepthFirstSearch();
    //t.BreadthFirstSearch();
    //t.InPrintNoRecursion();
    if (argc < 3) return -1;
    //int target = atoi(argv[1]);
    //if (t.find(t.root(), target)) printf("find %d\n", target);
    //else printf("not find: %d\n", target);
    int leftval = atoi(argv[1]);
    int rightval = atoi(argv[2]);
    BinaryTree::TreeNode *left = t.find(t.root(), leftval);
    if (left) printf("left: %d, %p\n", left->val, left);
    else printf("left: %d not found\n", leftval);
    BinaryTree::TreeNode *right = t.find(t.root(), rightval);
    if (right) printf("right: %d, %p\n", right->val, right);
    else printf("right: %d not found\n", rightval);
    BinaryTree::TreeNode *ancestor = t.lowestCommonAncestor(t.root(), left, right);
    if (ancestor)
        printf("ancestor of %d and %d: %d\n", leftval, rightval, ancestor->val);
    else
        printf("ancestor of %d and %d: not found\n", leftval, rightval);
}
