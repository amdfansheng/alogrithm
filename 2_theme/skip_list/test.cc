#include "skip_list.h"

#include <cstdio>
#include <string>

int main()
{
  SkipList<int, std::string> skipList;

  skipList.add(3, "3");
  skipList.add(1,"1");
  skipList.add(11,"11");
  skipList.add(16,"16");
  skipList.add(4,"4");
  skipList.add(2,"2");
  skipList.add(8,"8");

  printf("%s\n", skipList.search(3).data());
  printf("before remove: %lu\n", skipList.get_size());
  skipList.remove(3);
  printf("after remove: %lu\n", skipList.get_size());
  
  printf("contains: %s\n", skipList.contains(1) ? "yes" : "no");

  std::vector<std::string> val = skipList.range(8, 20);
  for (auto &&v : val) {
    printf(" %s", v.data());
  }
  printf("\n");

  printf("min: %s\n", skipList.findMin().data());
  printf("max: %s\n", skipList.findMax().data());
}
