#include <queue>
#include <cstdio>
#include <cassert>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        last = x;
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> cache;

        while(q1.size() != 1) {
            cache.push(q1.front());
            q1.pop();
        }

        int ret = last;
        q1.pop();
        assert(q1.empty());
        while(!cache.empty()) {
            if (cache.size() == 1) {
                last = cache.front();
            }
            q1.push(cache.front());
            cache.pop();
        }

        return ret;
    }

    /** Get the top element. */
    int top() {
        return last;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

    int last;
    queue<int> q1;
};

/** * Your MyStack object will be instantiated and called as such: */
int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    printf("pop: %d\n", param_2);
    int param_3 = obj->top();
    printf("top: %d\n", param_3);
    bool param_4 = obj->empty();
}

