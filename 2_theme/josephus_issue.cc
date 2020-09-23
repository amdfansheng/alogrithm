#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef struct _LinkNode {
    int value;
    struct _LinkNode *next;
} LinkNode, *LinkNodePtr;

LinkNodePtr createCycle(int total)
{
    int index = 1;
    LinkNodePtr head = NULL, curr = NULL, prev = NULL;
    head = (LinkNodePtr) malloc(sizeof(LinkNode));
    head->value = index;
    prev = head;

    while (--total > 0) {
        curr = (LinkNodePtr) malloc(sizeof(LinkNode));
        curr->value = ++index;
        prev->next = curr;
        prev = curr;
    }
    curr->next = head;
    return head;
}

void run(int total, int tag)
{
    LinkNodePtr node = createCycle(total);
    LinkNodePtr prev = NULL;
    int start = 1;
    int index = start;
    while (node && node->next) {
        if (index == tag) {
            printf("999999: %d\n", node->value);
            if (tag == start) {
                prev = node->next;
                node->next = NULL;
                node = prev;
            } else {
                prev->next = node->next;
                node->next = NULL;
                node = prev->next;
            }
            index = start;
        } else {
            prev = node;
            node = node->next;
            index++;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) { return -1; }
    run(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
