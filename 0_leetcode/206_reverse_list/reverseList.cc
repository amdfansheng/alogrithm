#include <cstdio>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    }
};

ListNode *creat(const vector<int> &vec)
{
    ListNode first, *pre = &first;
    for (auto &&v : vec) {
        ListNode *tmp = new ListNode(v);
        pre->next = tmp;
        pre = tmp;
    }
    return first.next;
}

void dump(const ListNode* l)
{
    for (const ListNode *cur = l; cur; cur = cur->next) {
        fprintf(stderr, "%d ", cur->val);
    }
    fprintf(stderr, "\n");
}

int main()
{
    vector<int> v1 = {-9,-7,-3,-3,-1,2,3};
    vector<int> v2 = {5};

    ListNode *l1 = creat(v1);
    ListNode *l2 = creat(v2);

    dump(l1);
    dump(l2);

}
