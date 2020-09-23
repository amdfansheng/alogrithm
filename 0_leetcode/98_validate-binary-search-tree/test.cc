#include "binary_tree.h"

using namespace std;

int main()
{
    //vector<int> vec = {5,1,4,INT_MAX,INT_MAX,3,6};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    BinaryTree t;
    t.BuildTree(vec);
    t.PrePrint();
    t.InPrint();
    t.PostPrint();
    t.DepthFirstSearch();
    t.BreadthFirstSearch();
    t.InPrintNoRecursion();
}
