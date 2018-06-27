// Problem 7: 10001st prime
// https://projecteuler.net/problem=7
// Answer: 104743

#include <iostream>
#include <vector>

using namespace std;

int main() {
  constexpr int limit = 200000;
  vector<char> s(limit);
  int i = 1, n = 1;
  while (true) {
    if (s[i += 2]) continue;
    if (++n == 10001) {
      cout << i << endl;
      return 0;
    }
    int j = i;
    while ((j += i) < limit)
      s[j] = true;
  }
}
