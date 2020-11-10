#include "binary_tree.h"
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    BinaryTree tree;
    tree.BuildTree(nums);

    tree.PrePrint();
    tree.InPrint();
    tree.PostPrint();

    tree.PrePrintNoRecursion();
    tree.InPrintNoRecursion();
    tree.PostPrintNoRecursion();
}
