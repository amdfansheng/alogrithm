#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <climits>


class BinaryTree {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    TreeNode *root() { return root_; }

    void BuildTree(const std::vector<int> &nums)
    {
        build_tree(root_, nums, 0);
    }

    void PrePrint()
    {
        printf("preorder traversal: ");
        pre_print(root_);
        printf("\n");
    }

    void InPrint()
    {
        printf("inorder traversal: ");
        in_print(root_);
        printf("\n");
    }

    void PostPrint()
    {
        printf("postorder traversal: ");
        post_print(root_);
        printf("\n");
    }

    // 效果等同于前序遍历
    void DepthFirstSearch()
    {
        printf("DFS: ");
        std::stack<TreeNode *> nstack;

        nstack.push(root_);
        while (!nstack.empty()) {
            TreeNode *top = nstack.top();
            printf("%d ", top->val);
            nstack.pop();

            if (top->right) nstack.push(top->right);
            if (top->left) nstack.push(top->left);
        }

        printf("\n");
    }

    void BreadthFirstSearch()
    {
        printf("BFS: ");
        std::queue<TreeNode *> nqueue;

        nqueue.push(root_);
        while (!nqueue.empty()) {
            TreeNode *front = nqueue.front();
            printf("%d ", front->val);
            nqueue.pop();

            if (front->left) nqueue.push(front->left);
            if (front->right) nqueue.push(front->right);
        }

        printf("\n");
    }

    void InPrintNoRecursion()
    {
        printf("inorder traversal (Non Recursion): ");
        std::stack<TreeNode *> nstack;

        TreeNode *node = root_;
        while (!nstack.empty() || node) {
            while (node) {
                nstack.push(node);
                node = node->left;
            }

            node = nstack.top();
            printf("%d ", node->val);
            nstack.pop();

            node = node->right; // 如果右儿子非空，把右儿子看成根，如果右儿子为空，说明左树已经打印完毕
        }

        printf("\n");
    }

private:
    TreeNode *root_ = nullptr;

    void build_tree(TreeNode *&node, const std::vector<int> &nums, int index)
    {
        if (index >= nums.size() ||
            nums[index] == INT_MAX) return;
        node = new TreeNode(nums[index]);
        build_tree(node->left, nums, 2 * index + 1);
        build_tree(node->right, nums, 2 * index + 2);
    }

    void pre_print(TreeNode *node)
    {
        if (!node) return;

        printf("%d ", node->val);
        pre_print(node->left);
        pre_print(node->right);
    }

    void in_print(TreeNode *node)
    {
        if (!node) return;

        in_print(node->left);
        printf("%d ", node->val);
        in_print(node->right);
    }

    void post_print(TreeNode *node)
    {
        if (!node) return;

        post_print(node->left);
        post_print(node->right);
        printf("%d ", node->val);
    }
};

