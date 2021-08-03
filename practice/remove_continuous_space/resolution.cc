#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

void remove_space(char *str)
{
  if (!str) return;
  std::string buf;
  buf.resize(strlen(str));

  size_t buf_c = 0;
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (str[i] != ' ' || (str[i] == ' ' && str[i - 1] != ' ')) {
      buf[buf_c] = str[i];
      ++buf_c;
    }
  }

  memcpy(str, buf.data(), buf.size());
}

void remove_space2(char *str)
{
  if (!str) return;

  size_t end = strlen(str);
  size_t slow = 0;
  for (size_t fast = 1; fast != end; ++fast) {
    // if (str[slow] == ' ' && str[fast] == ' ') {
      // continue;
    // }
    // str[++slow] = str[fast];
    if (!(str[slow] == ' ' && str[fast] == ' ')) {
      str[++slow] = str[fast];
    }
  }
  str[slow + 1] = '\0';
}


void remove_space3(char *str)
{
  *std::unique(str, str + strlen(str), [] (char i, char y) { return i == ' ' && y == ' '; }) = '\0';
}

int main(int argc, char *argv[])
{
  if (argc < 2) return -1;

  printf("%s\n", argv[1]);
  remove_space3(argv[1]);
  printf("%s\n", argv[1]);
}
