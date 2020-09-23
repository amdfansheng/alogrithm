#include <cstdio>
#include <cstdlib>
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

ListNode* reverseList(ListNode* l, int k) {
    ListNode *cur = l, *pre = nullptr;
    int count{};
    while (cur && count != k) {
        ListNode *tmp = cur->next;
        cur->next = pre; // key state
        pre = cur;
        cur = tmp;
        ++count;
    }
    l->next = cur;
    return pre;
}

ListNode *reverseKGroup(ListNode* head, int k)
{
    ListNode *ret, *cur = head, *pretail = NULL, *newhead = NULL;
    bool first{};
    int count{};
    while (cur) {
        cur = cur->next;
        if (k != ++count) continue;
        count = 0;

        newhead = reverseList(head, k);
        if (pretail) pretail->next = newhead;
        pretail = head;
        head = cur;
        if (!first) {
            ret = newhead;
            first = true;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("reverseKGroup k\n");
        return -1;
    }
    vector<int> v2 = {5};

    vector<int> v1 = {1, 2, 3, 4, 5};
    ListNode *l1 = creat(v1);
    dump(l1);
    //l1 = reverseList(l1, atoi(argv[1]));
    l1 = reverseKGroup(l1, atoi(argv[1]));
    dump(l1);

    //ListNode *l2 = creat(v2);
    //dump(l2);
}
