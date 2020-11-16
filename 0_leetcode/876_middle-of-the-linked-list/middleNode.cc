#include <cstdio>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val = 0;
    ListNode *next = nullptr;

    ListNode() {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Solution s;
    auto head = s.createList(nums);
    s.dump(head);

    auto mid = s.middleNode(head);
    s.dump(mid);
}
