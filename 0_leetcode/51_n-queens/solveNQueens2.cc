// 黄晨成给的解法
// 没有理解思路 2020.09.30
#include <iostream>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <utility>
#include <iterator>

int main() {
  int queens[] = {0, 1, 2, 3, 4, 5, 6, 7};

  auto lhs = [&](std::pair<int, int> a, int b) {
    return std::make_pair((1 << (b + a.second)) | a.first, a.second + 1);
  };
  auto rhs = [&](std::pair<int, int> a, int b) {
    return std::make_pair((1 << (7 + b - a.second)) | a.first, a.second + 1);
  };

  while (std::next_permutation(std::begin(queens), std::end(queens))) {
    std::bitset<15> l{std::accumulate(std::begin(queens), std::end(queens), std::make_pair(0, 0), lhs).first};
    if (l.count() == 8) {
      std::bitset<15> r{std::accumulate(std::begin(queens), std::end(queens), std::make_pair(0, 0), rhs).first};
      if (r.count() == 8) {
        std::copy(std::begin(queens), std::end(queens), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
      }
    }
  }
}
