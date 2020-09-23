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

ListNode *swapPairs(ListNode *l)
{
    if (!l || !l->next) return l;

    ListNode fake;
    ListNode *cur = l, *pre = &fake;
    while (cur && cur->next) {
        ListNode *nxt = cur->next;

        pre->next = nxt;

        cur->next = nxt->next;
        nxt->next = cur;

        pre = cur;
        cur = cur->next;
    }
    return fake.next;
}

int main()
{
    vector<int> v1 = {-9,-7,-5,-3,-1,2,3,4};
    ListNode *l1 = creat(v1);
    dump(l1);
    l1 = reverse(l1);
    dump(l1);

    //vector<int> v2 = {5, 3};
    //vector<int> v2 = {5, 3, 2};
    //vector<int> v2 = {5, 3, 2, 1};
    vector<int> v2 = {-9,-7,-5,-3,-1,2,3,4};
    ListNode *l2 = creat(v2);
    dump(l2);
    //ListNode *t = l2->next;
    //swap(l2, t);
    l2 = swapPairs(l2);
    dump(l2);
}
