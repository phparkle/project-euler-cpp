// Problem 12: Highly divisible triangular number
// https://projecteuler.net/problem=12
// Answer: 76576500

#include <iostream>

using namespace std;

int main() {
  int n = 0;
  int d = 0;
  int i = 1;
  while (d <= 500) {
    n += i++;
    d = 0;
    int j = 1;
    while (j * j < n)
      if (n % j++ == 0)
        d += 2;
    if (j * j == n)
      ++d;
  }
  cout << n << endl;
}
