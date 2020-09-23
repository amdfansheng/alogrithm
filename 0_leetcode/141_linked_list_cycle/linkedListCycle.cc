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

bool hasCycle(ListNode *head)
{
    if (!head) return false;
    struct ListNode *slow = head->next, *fast = slow;
    if (!slow) return false;

    while(slow && fast) {
        if (!slow->next) return false;
        if (!fast->next || !fast->next->next) return false;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }

    return false;
}

bool hasCycle2(ListNode *head)
{
    if (!head || !head->next) return false;
    struct ListNode *slow = head, *fast = head->next;

    while(slow != fast) {
        if (!fast || !fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

// best code
bool hasCycle3(ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }

    return false;
}

int main()
{
    vector<int> v2 = {5};

    vector<int> v1 = {3, 2, 0, 4};
    ListNode *l1 = creat_with_cycle(v1, 1);
    dump(l1, 1);
    printf("%s\n", hasCycle3(l1)?"has":"no-has");

    //ListNode *l2 = creat(v2);
    //dump(l2);
}
