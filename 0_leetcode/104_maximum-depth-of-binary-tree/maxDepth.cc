#include "binary_tree.h"

using namespace std;

class Solution : public BinaryTree {
public:
    // 递归 DFS
    int maxDepth(TreeNode *root)
    {
        if (!root) return 0;

        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);

        return ld > rd ? ld + 1 : rd + 1;
    }

    // 非递归 DFS
    int maxDepth2(TreeNode *root)
    {
        if (!root) return 0;

        struct NodeWrap {
            TreeNode *node;
            int depth;
        };


        int max_dep{};
        stack<NodeWrap> memo;
        memo.push({root, 1});
        while(!memo.empty()) {
            NodeWrap nw = memo.top();
            int cur_dep = nw.depth;
            TreeNode *node = nw.node;
            memo.pop();

            if (cur_dep > max_dep) max_dep = cur_dep;

            if (node->right) memo.push({node->right, cur_dep + 1});
            if (node->left)  memo.push({node->left, cur_dep + 1});
        }
        return max_dep;
    }

    // BFS
    int maxDepth3(TreeNode *root)
    {
        if (!root) return 0;

        int depth{};
        queue<TreeNode *> memo;
        memo.push(root);
        while (!memo.empty()) {
            int size = memo.size();
            while (size-- > 0) {
                TreeNode *node = memo.front();
                memo.pop();

                if (node->left) memo.push(node->left);
                if (node->right) memo.push(node->right);
            }
            ++depth;
        }

        return depth;
    }
};

int main()
{
    //vector<int> nums = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    vector<int> nums = {1, 2, 3, 4, INT_MAX, INT_MAX, 5};

    Solution s;
    s.BuildTree(nums);
    s.BreadthFirstSearch();

    int depth = s.maxDepth3(s.root());
    printf("depth: %d\n", depth);
}
