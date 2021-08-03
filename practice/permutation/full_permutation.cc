#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
  std::vector<int> vec = {1, 2, 3, 4};

  int count {};
  do {
    std::cout << ++count << ": ";
    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
  } while (std::next_permutation(vec.begin(), vec.end()));
}
