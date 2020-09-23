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
        q1.push(x);
        for (size_t sz = q1.size(); sz != 1; --sz) {
            q1.push(q1.front());
            q1.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q1.front();
        q1.pop();

        return ret;
    }

    /** Get the top element. */
    int top() {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

    queue<int> q1;
};

/** * Your MyStack object will be instantiated and called as such: */
int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    int param_2 = obj->pop();
    printf("pop: %d\n", param_2);
    int param_3 = obj->top();
    printf("top: %d\n", param_3);
    bool param_4 = obj->empty();
}

