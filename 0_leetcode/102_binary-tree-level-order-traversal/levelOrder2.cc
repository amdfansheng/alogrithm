#include "binary_tree.h"

using namespace std;

class Solution : public BinaryTree {
public:
    // 1个队列, 巧妙
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector <vector<int>> ret;
        if (!root) return ret;

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {

            int currentLevelSize = q.size();
            ret.push_back(vector<int>());

            for (int i = 0; i < currentLevelSize; ++i) {
                auto node = q.front();
				q.pop();

                ret.back().push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ret;
    }
};


int main()
{
    vector<int> nums = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};

    Solution s;
    s.BuildTree(nums);
    s.BreadthFirstSearch();

    vector<vector<int>> result = s.levelOrder(s.root());
    for (auto &&vec : result) {
        for (auto &&v : vec) {
            printf("%d, ", v);
        }
        printf("\n");
    }
}
