#include <cstdio>
#include <cstdlib>

int DAYMAP[] = {0,
                31, 28, 31, 30,
                31, 30, 31, 31,
                30, 31, 30, 31};

 int dayOfYear(int year, int month, int day)
{
    if (year < 0) return -1;
    if ((year % 4 == 0 && year % 100 != 0) ||
        year % 400 == 0)
        DAYMAP[2] += 1;

    if (month < 1 || month > 12) return -1;
    if (day < 1 || day > DAYMAP[month]) return -1;

    int days{};
    for (int m = month - 1; m > 0; --m) {
        days += DAYMAP[m];
    }

    return days + day;
}

int main(int argc, char *argv[])
{
    if (argc < 4) return -1;
    printf("%d\n", dayOfYear(atoi(argv[1]),
                             atoi(argv[2]),
                             atoi(argv[3])));
    return 0;
}
