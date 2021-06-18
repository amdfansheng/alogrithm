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

    // -------------------------
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

    // -------------------------
    // 详解：https://blog.csdn.net/Benja_K/article/details/88389039
    // 从当前节点开始遍历：（当入栈时访问节点内容，则为前序遍历；出栈时访问，则为中序遍历）
    // 1. 若当前节点存在，就存入栈中，并访问左子树；
    // 2. 直到当前节点不存在，就出栈，并通过栈顶节点访问右子树；
    // 3. 不断重复12，直到当前节点不存在且栈空。
    void PrePrintNoRecursion()
    {
        printf("preorder traversal (Non Recursion): ");
        std::stack<TreeNode *> nstack;

        TreeNode *node = root_;
        while (node || !nstack.empty()) {
            if (node) { //两种情况：1.栈不空；2.栈空
                printf("%d ", node->val); // 入栈前，访问输出
                nstack.push(node);
                node = node->left;
            } else { //一种情况：当前节点为空，但栈不空
                node = nstack.top();
                nstack.pop();
                node = node->right;
            }
        }

        printf("\n");
    }

    void InPrintNoRecursion()
    {
        printf("inorder traversal (Non Recursion): ");
        std::stack<TreeNode *> nstack;

        TreeNode *node = root_;
        while (node || !nstack.empty() ) {
            if (node) {
                nstack.push(node);
                node = node->left;
            } else {
                node = nstack.top();
                printf("%d ", node->val); // 出栈时访问
                nstack.pop();

                node = node->right;
            }
        }

        printf("\n");
    }

    void PostPrintNoRecursion()
    {
        printf("postorder traversal (Non Recursion): ");
        struct NodeWrapper {
            TreeNode *node = nullptr;
            int flag = 0; // 记录每个节点访问次数栈
        };
        std::stack<NodeWrapper> nstack;

        TreeNode *node = root_;
        while (node|| !nstack.empty() ) {
            if (node) { // 第一次访问，flag置1，入栈
                nstack.push({node, 1});
                node = node->left;
            } else {
                NodeWrapper tn = nstack.top();
                int flag = tn.flag;
                if (flag == 1) { // 第二次访问，flag置2，取栈顶元素但不出栈
                    nstack.top().flag = 2;
                    node = tn.node->right;
                } else { // 第三次访问，出栈
                    printf("%d ", tn.node->val); // 出栈时访问
                    nstack.pop();

                    node = nullptr;
                }
            }
        }

        printf("\n");
    }

    // -------------------------
    // 效果等同于前序遍历, 非递归的技巧性写法
    void DepthFirstSearch()
    {
        printf("DFS: ");
        std::stack<TreeNode *> nstack;

        nstack.push(root_);
        while (!nstack.empty()) {
            TreeNode *top = nstack.top();
            printf("%d ", top->val); // process
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

private:
    TreeNode *root_ = nullptr;

    void build_tree(TreeNode *&node, const std::vector<int> &nums, int index)
    {
        if (index >= nums.size() || nums[index] == INT_MAX) return;

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

