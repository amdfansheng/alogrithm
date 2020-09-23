#include <cstdio>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        return nullptr;
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

ListNode *reverse_old(ListNode *l)
{
    if (!l || !l->next) return l;

    ListNode *pre = nullptr, *tmp = nullptr;
    for (ListNode *cur = l, *n = cur->next; n; cur = tmp, n = cur->next) {
        fprintf(stderr, "cur%d ", cur->val);
        fprintf(stderr, "nxt%d ", n->val);

        cur->next = pre;

        tmp = n->next;
        n->next = cur;
        if (!tmp) {
            fprintf(stderr, "n->next null \n");
            return n;
        }
        pre = n;
    }
    tmp->next = pre;
    fprintf(stderr, "\n");
    return tmp;
}

ListNode *reverse(ListNode *l)
{
    if (!l || !l->next) return l;

    ListNode *cur = l, *pre = nullptr;
    while (cur) {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

int main()
{
    vector<int> v1 = {-9,-7,-3,-3,-1,2,3,4};
    ListNode *l1 = creat(v1);
    dump(l1);
    l1 = reverse(l1);
    dump(l1);

    //vector<int> v2 = {5};
    //ListNode *l2 = creat(v2);
    //dump(l2);
    //l2 = reverse(l2);
    //dump(l2);
}
