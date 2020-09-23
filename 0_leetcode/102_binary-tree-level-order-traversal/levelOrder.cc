#include "binary_tree.h"

using namespace std;

class Solution : public BinaryTree {
public:
	// 自己写的，笨了点
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        if (!root) return ret;

        std::queue<TreeNode *> nqueue;
        std::vector<TreeNode *> nvector;

        nvector.push_back(root);
        while (!nvector.empty()) {

            for (auto &&v : nvector) {
                nqueue.push(v);
            }
            nvector.clear(); // 这儿有坑，没有这句，会死循环

            vector<int> tmp;
            while (!nqueue.empty()) {
                TreeNode *front = nqueue.front();
                tmp.emplace_back(front->val);
                //printf("%d ", front->val);
                nqueue.pop();

                if (front->left) nvector.push_back(front->left);
                if (front->right) nvector.push_back(front->right);
            }
            ret.emplace_back(std::move(tmp));
            //printf("\n");

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
