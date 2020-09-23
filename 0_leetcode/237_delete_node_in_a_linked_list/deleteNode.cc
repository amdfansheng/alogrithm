#include <cstdio>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    int tag;
    ListNode *next;
    ListNode(int x) : val(x), tag(0), next(NULL) {}
};

ListNode *creat(const vector<int> &vec)
{
    ListNode first(8), *pre = &first;
    ListNode *tmp{nullptr};
    for (auto &&v : vec) {
        tmp = new ListNode(v);
        pre->next = tmp;
        pre = tmp;

    }
    return first.next;
}

void dump(ListNode* l)
{
    for (ListNode *cur = l; cur; cur = cur->next) {
        fprintf(stderr, "%d ", cur->val);
    }
    fprintf(stderr, "\n");
}

ListNode *find(ListNode* l, int val)
{
    for (ListNode *cur = l; cur; cur = cur->next) {
        if (cur->val == val) return cur;
    }
    return nullptr;
}

void deleteNode(struct ListNode* node)
{
    node->val = node->next->val;
    struct ListNode *del = node->next;
    node->next = node->next->next;
    free(del);
}

int main()
{
    vector<int> v2 = {5};

    vector<int> v1 = {3, 2, 0, 4};
    ListNode *l1 = creat(v1);
    dump(l1);
    //printf("%s\n", hasCycle3(l1)?"has":"no-has");

    //ListNode *l2 = creat(v2);
    //dump(l2);
}
