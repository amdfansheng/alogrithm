#include <stack>
#include <cstdio>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stk.empty()) return -1;

        stack<int> cache;
        while(!stk.empty()) {
            cache.push(stk.top());
            stk.pop();
        }
        int ret = cache.top();
        cache.pop();
        while (!cache.empty()) {
            stk.push(cache.top());
            cache.pop();
        }
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if (stk.empty()) return -1;

        stack<int> cache;
        while(!stk.empty()) {
            cache.push(stk.top());
            stk.pop();
        }
        int ret = cache.top();
        while (!cache.empty()) {
            stk.push(cache.top());
            cache.pop();
        }
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }

    size_t size() {
        return stk.size();
    }

    stack<int> stk;
};

// Your MyQueue object will be instantiated and called as such:
int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    //obj->push(3);
    //printf("size: %zu\n", obj->size());
    int param_3 = obj->peek();
    printf("peek(): %d\n", param_3);
    printf("size: %zu\n", obj->size());
    int param_2 = obj->pop();
    printf("pop(): %d\n", param_2);

    printf("size(): %zu\n", obj->size());
    bool param_4 = obj->empty();
}
