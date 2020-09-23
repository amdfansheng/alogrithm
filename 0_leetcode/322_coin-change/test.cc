#include <cstdio>
#include <algorithm>

int main()
{
    int arr[5] = {8, 3, 6, 1, 5};
    std::sort(arr, arr + 5);

    printf("%d\n", arr[0]);
}
