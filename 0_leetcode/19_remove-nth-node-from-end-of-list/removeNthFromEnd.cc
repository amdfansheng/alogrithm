#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val = 0;
    ListNode *next = nullptr;

    ListNode() {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 快慢指针法，让快指针先走 n 步，然后快慢指针开始同速前进。这样当快指针走到链表末尾 null 时，慢指针所在的位置就是倒数第 n 个链表节点（n 不会超过链表长度）
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        while (n-- > 0) {
            fast = fast->next;
        }
        if (!fast) return head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }

    // 根据栈「先进后出」的原则，我们弹出栈的第 nn 个节点就是需要删除的节点，并且目前栈顶的节点就是待删除节点的前驱节点。这样一来，删除操作就变得十分方便了
    ListNode *removeNthFromEnd2(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        stack<ListNode *> stk;
        ListNode *cur = dummy;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }
        ListNode *prev = stk.top();
        prev->next = prev->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }


    ListNode *createList(const vector<int> &vec)
    {
        ListNode fake, *pre = &fake;
        for (auto &&v : vec) {
            ListNode *tmp = new ListNode(v);
            pre->next = tmp;
            pre = tmp;
        }
        return fake.next;
    }

    void dump(ListNode *head)
    {
        while (head) {
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;
    int n = atoi(argv[1]);
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Solution s;
    auto head = s.createList(nums);
    s.dump(head);

    auto p = s.removeNthFromEnd2(head, n);
    s.dump(p);
}
