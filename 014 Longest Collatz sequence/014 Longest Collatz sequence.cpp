// Problem 14: Longest Collatz sequence
// https://projecteuler.net/problem=14
// Answer: 837799

#include <iostream>

using namespace std;

int main() {
  int imax = 0;
  int cmax = 0;
  int i = 1;
  while (i < 1000000) {
    long long n = i;
    int c = 1;
    while (n != 1) {
      if (n & 1) {
        n = ((n << 1) | 1) + n;
        ++c;
      }
      n >>= 1;
      ++c;
    }
    if (c > cmax) {
      imax = i;
      cmax = c;
    }
    i += 2;
  }
  cout << imax << endl;
}
