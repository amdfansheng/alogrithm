#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n)
  {
    vector<std::string> res;
    recursive_search(n, n, "", &res);
    return res;
  }

 private:
  void recursive_search(int left, int right, std::string generated, std::vector<std::string>* res)
  {
    if (left == 0 and right == 0) {
      res->push_back(generated);
    } else {
      if (right > 0 and left < right) {
        recursive_search(left, right - 1, generated + ")", res);
      }
      if (left > 0) {
        recursive_search(left - 1, right, generated + "(", res);
      }
    }
  }

};

int main(int argc, char *argv[])
{
    if (argc < 2) return -1;

    int n = atoi(argv[1]);
    Solution s;
    vector<string> ret = s.generateParenthesis(n);
    printf("n: %d\n", n);

    for (auto &&item : ret) {
        printf("%s\n", item.data());
    }
}
