#include <climits>
#include <stdint.h>

int my_atoi(char *s)
{
  if (!s || !*s) return 0;

  // static int digits[10] = {
    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  // };
  int64_t i {};
  bool neg {};

  for (; *s; ++s) {
    if (*s == ' ') continue;
    if (*s == '-') {
      neg = true;
      ++s;
      break;
    }
    if (*s == '+') {
      ++s;
      break;
    }
    if (*s > 47 && *s < 58) { break; }
    return 0;
  }
  
  for (; *s != '\0'; ++s) {
    if (*s < 48 || *s > 57) { break; }
    i *= 10;
    // i += digits[*s - 48];
    i += *s - 48;
    if (i > (int64_t)INT_MAX + 1) { break; }
  }

  if (neg) {
    i = -i;
    if (i < INT_MIN) i = INT_MIN;
  } else {
    if (i > INT_MAX) i = INT_MAX;
  }

  return (int)i;
}

