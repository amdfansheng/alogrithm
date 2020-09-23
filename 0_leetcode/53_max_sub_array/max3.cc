#include <cstdio>
#include <cstdlib>

int max3( int a, int b, int c )
{
    return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

int main(int argc, char *argv[])
{
    if (argc < 4) return -1;
    printf("%d\n", max3(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));
}
