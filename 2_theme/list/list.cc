#include <list>
#include <iostream>

using namespace std;


int main()
{
    list<int> li {10, 20, 30, 40};

    li.insert(li.end(), 30);

    li.remove(30);

    for (auto &&v : li) {
        cout << v << " ";
    }
    cout << endl;
}
