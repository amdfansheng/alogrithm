#include <vector>
#include <queue>
#include <cstdio>
#include <limits.h>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> min_head;

    min_head.push(0);
    min_head.push(5);
    min_head.push(8);
    min_head.push(2);
    min_head.push(9);

    while(!min_head.empty()) {
        printf("%d \n", min_head.top());
        min_head.pop();
    }
}
