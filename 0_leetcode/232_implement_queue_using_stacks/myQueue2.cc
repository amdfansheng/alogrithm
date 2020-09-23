#include <stack>
#include <cstdio>

using namespace std;

class MyQueue {
public:
    /** Push element x to the back of queue. */
    void push(int x) {
        if (stk_in.empty()) front = x;
        stk_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stk_out.empty()) {
            while(!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }

        int ret = stk_out.top();
        stk_out.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if (!stk_out.empty())
            return stk_out.top();
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk_in.empty() && stk_out.empty();
    }

    size_t size() {
        return stk_in.size() + stk_out.size();
    }

    int front;

    stack<int> stk_in;
    stack<int> stk_out;
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
