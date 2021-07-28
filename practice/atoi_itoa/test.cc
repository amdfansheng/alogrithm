#include <cstdio>
#include <cstdlib>

#include "itoa.h"
#include "atoi.h"

int main(int argc, char *argv[])
{
  if (argc < 2) return -1;
  // int num = atoi(argv[1]);

  // printf("%s/10: %d\n", argv[1], num / 10);
  // printf("%s%%10: %d\n", argv[1], num % 10);

  // char buf[32] = {};
  // itoa(buf, num);
//
  // printf("itoa(): %s\n", buf);
  //
  // char buf[] = "    -42";
  // char buf[] = "4193 with words";
  // char buf[] = "-91283472332";
  char buf[] = "21474836460";
  printf("%d\n", my_atoi(buf));

  printf("%d\n", INT_MAX);
}
