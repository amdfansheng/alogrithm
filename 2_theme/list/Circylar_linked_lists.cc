#include <cstdio>
#include <cstdlib>

typedef struct node {
    int value = -1;
    struct node *next = nullptr;
} Node, *NodeList;

NodeList build(int n)
{
    NodeList head = nullptr, pre = nullptr;
    for (int i = 0; i < n; ++i) {
        NodeList cur = (NodeList)calloc(sizeof(Node), sizeof(char));
        cur->value = i;
        if (!head) head = cur;
        if (pre && !pre->next) pre->next = cur;
        pre = cur;
        //printf("create: %d\n", i);
    }
    pre->next = head;

    return head;
}

void dump(NodeList head, int size)
{
    int num {0};
    for (NodeList cur = head; cur; cur = cur->next) {
        if (num == size) break;
        printf("list node: %d\n", cur->value);
        ++num;
    }
}

void josephus(int n, int k, int m)
{
    NodeList head = build(n);
    //dump(head, n);

    int size = n;
    int skip {1}, out {1};
    for (NodeList pre = nullptr, cur = head; cur; pre = cur, cur = cur->next) {
        if (skip < k) {
            printf("size: %d, num: %d, skip: %d\n", size, cur->value, skip);
            ++skip;
            continue;
        }

        if (out < m) {
            printf("size: %d, num: %d, count_off: %d\n", size, cur->value, out);
            ++out;
            continue;
        }

        printf("number node %d out list~!\n", cur->value);
        pre->next = cur->next;
        free(cur);
        cur = pre;
        skip = out = 1;

        --size;
        if (!size) break;
    }

}

int main()
{
    josephus(10, 3, 2);
}
