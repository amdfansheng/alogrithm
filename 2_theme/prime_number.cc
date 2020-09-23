#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int n, i;
  bool isPrime = true;

  cout << "输入一个正整数: ";
  cin >> n;
  //n = 29;

  int hn = n / 2;
  printf("%d / 2: %d\n", n, hn);
  for (i = 2; i <= hn; ++i) {
	  printf("%d %% %d: %d\n", n, i, n % i);
      if (n % i == 0) {
          isPrime = false;
          break;
      }
  }
  if (isPrime)
      cout << "是素数" << endl;
  else
      cout << "不是素数" << endl;

  return 0;
}
