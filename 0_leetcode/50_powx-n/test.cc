#include <cstdio>
#include <cstdlib>
int main(int argc, char *argv[])
{
    int i = atoi(argv[1]);
    printf("%d / 2: %d\n", i, i / 2);
    printf("%d % 2: %d\n", i, i % 2);
}
