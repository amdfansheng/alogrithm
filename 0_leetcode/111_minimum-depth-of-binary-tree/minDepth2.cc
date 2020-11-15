#include "binary_tree.h"

using namespace std;

class Solution : public BinaryTree {
public:
	// DFS, 递归
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1; // 左为空
        if (!root->right) return minDepth(root->left) + 1; // 右为空
        // 左右都不空
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);

        return ld < rd ? ld + 1 : rd + 1;
    }

    // DFS with stack
    int minDepth2(TreeNode* root)
    {
        if (!root) return 0;

        struct NodeWrap {
            TreeNode *node;
            int depth;
        };

        int min_dep{INT_MAX};
        stack<NodeWrap> memo;
        memo.push({root, 1});
        while (!memo.empty()) {
            NodeWrap nw = memo.top();
            TreeNode *node = nw.node;
            int dep = nw.depth;
            memo.pop();

            if (!node->right && !node->left) min_dep > dep ? min_dep = dep : 0;

            if (node->right) memo.push({node->right, dep + 1}); // 先放右再放左
            if (node->left)  memo.push({node->left, dep + 1});
        }

        return min_dep;
    }

    // BFS
    int minDepth3(TreeNode* root)
    {
        if (!root) return 0;

        int depth{}; // root 本身就是一层，depth 初始化为 1
        queue<TreeNode *> memo;
        memo.push(root);
        while (!memo.empty()) {
            ++depth;
            int size = memo.size();
            while (size-- > 0) {
                TreeNode *node = memo.front();
                memo.pop();

                if (!node->right && !node->left) return depth;

                if (node->left) memo.push(node->left); // 先放左再放右
                if (node->right) memo.push(node->right);
            }
        }

        return depth;
    }
};

int main()
{
    //vector<int> nums = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    //vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums = {1, 2, 3, 4, INT_MAX, INT_MAX, 5};
    //vector<int> nums = {1, 2, 3, 4};

    Solution s;
    s.BuildTree(nums);
    s.BreadthFirstSearch();

    int depth = s.minDepth3(s.root());
    printf("depth: %d\n", depth);
}

