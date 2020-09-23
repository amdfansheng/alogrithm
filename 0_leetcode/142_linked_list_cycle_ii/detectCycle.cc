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

ListNode *creat_with_cycle(const vector<int> &vec, size_t pos)
{
    ListNode first(8), *pre = &first;
    ListNode *cross{nullptr}, *tmp{nullptr};
    for (auto &&v : vec) {
        tmp = new ListNode(v);
        pre->next = tmp;
        pre = tmp;

        if (v == vec[pos]) cross = tmp;
    }
    tmp->next = cross;
    return first.next;
}

void dump(ListNode* l, size_t pos)
{
    size_t pos_now{};
    for (ListNode *cur = l; cur; cur = cur->next) {
        fprintf(stderr, "%d ", cur->val);
        if (cur->tag == -1) break;
        if (pos_now++ == pos) cur->tag = -1;
    }
    fprintf(stderr, "\n");
}

ListNode *get_inter(ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;
    }

    return NULL;
}


ListNode *detectCycle(ListNode *head)
{
    struct ListNode *intersect = get_inter(head);
    if (!intersect) return NULL;

    struct ListNode *start = head;
    while (start != intersect) {
        start = start->next;
        intersect = intersect->next;
    }
    return start;
}

int main()
{
    vector<int> v2 = {5};

    vector<int> v1 = {3, 2, 0, 4};
    ListNode *l1 = creat_with_cycle(v1, 1);
    dump(l1, 1);
    ListNode *ret = detectCycle(l1);
    printf("%s, %d\n", ret?"has":"no-has", ret?ret->val:-1);

    //ListNode *l2 = creat(v2);
    //dump(l2);
}
