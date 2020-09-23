#include <cstdio>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//class Solution {
//public:
    //ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    //}
//};

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

ListNode* seek_noless(ListNode* l, int t)
{
    ListNode *pre{};
    for (ListNode *cur = l; cur; pre = cur, cur = cur->next) {
        if (cur->val <= t) continue;
        break;
    }
    return pre;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (!l1 && !l2) return nullptr;
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode *first{};
    l1->val <= l2->val ? first = l1 : first = l2;
    ListNode *cursor{};
    while (1) {
        int l1cv = l1->val;
        int l2cv = l2->val;

        if (l2cv >= l1cv) goto seekl1;
        else if (l2cv < l1cv) goto seekl2;

seekl1:
        cursor = seek_noless(l1, l2cv);
        l1 = cursor->next;
        cursor->next = l2;
        if (!l1) break;
        continue;
seekl2:
        cursor = seek_noless(l2, l1cv);
        l2 = cursor->next;
        cursor->next = l1;
        if (!l2) break;
        continue;
    }
    return first;
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2)
{
    if (!l1) return l2;
    if (!l2) return l1;
    if (!l1 && !l2) return nullptr;

    ListNode *rst{}, *tail{};
    if (l1->val <= l2->val) {
        rst = l1;
        l1 = l1->next;
        rst->next = tail = l2;
        l2 = l2->next;
    } else {
        rst = l2;
        l2 = l2->next;
        rst->next = tail = l1;
        l1 = l1->next;
    }
    for (; l1 && l2;) {
        if (l1->val <= l2->val) {
            tail = tail->next = l1;
            l1 = l1->next;
            tail = tail->next = l2;
            l2 = l2->next;
        } else {
            tail = tail->next = l2;
            l2 = l2->next;
            tail = tail->next = l1;
            l1 = l1->next;
        }
    }
    if (!l1 && l2) {
        tail->next = l2;
    }
    if (!l2 && l1) {
        tail->next = l1;
    }
    return rst;
}

int main()
{
    //vector<int> v1 = {1, 2, 6, 6, 8};
    //vector<int> v2 = {1, 1, 5, 7};
    vector<int> v1 = {-9,-7,-3,-3,-1,2,3};
    vector<int> v2 = {5};

    ListNode *l1 = creat(v1);
    ListNode *l2 = creat(v2);

    dump(l1);
    dump(l2);

    ListNode * ret = mergeTwoLists(l1, l2);
    dump(ret);
}
