#include <algorithm>

const char *itoa(char buf[], int value)
{
  static char digits[19] = {
    '9', '8', '7', '6', '5', '4', '3', '2', '1', '0',
    '1', '2', '3', '4', '5', '6', '7', '8', '9'
  };
  static const char *zero = digits + 9;

  char *p = buf;
  int i = value;

  do {
    *p++ = zero[i % 10];
    i /= 10;
  } while (i);

  if (value < 0) { *p++ = '-'; }
  *p = 0;

  std::reverse(buf, p);

  return p;
}

