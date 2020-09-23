#include "binary_tree.h"

using namespace std;

class Solution : public BinaryTree {
public:
    // DFS, 巧妙
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root) return ret;
        levelOrderIn(root, 0);
        return ret;
    }

    void levelOrderIn(TreeNode *node, int level)
    {
        if (!node) return;

        if (ret.size() < level + 1) ret.emplace_back(vector<int>());

        ret[level].emplace_back(node->val);

        levelOrderIn(node->left, level + 1);
        levelOrderIn(node->right, level + 1);
    }

    vector<vector<int>> ret;
};


int main()
{
    //vector<int> nums = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    vector<int> nums = {1,2,3,4,5};

    Solution s;
    s.BuildTree(nums);
    s.BreadthFirstSearch();
    s.PrePrint();

    vector<vector<int>> result = s.levelOrder(s.root());
    for (auto &&vec : result) {
        for (auto &&v : vec) {
            printf("%d, ", v);
        }
        printf("\n");
    }
}
