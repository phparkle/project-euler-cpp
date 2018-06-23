// Problem 2: Even Fibonacci numbers
// https://projecteuler.net/problem=2
// Answer: 4613732

#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  int a = 1;
  int b = 2;
  while (a < 4 * 1000 * 1000) {
    if (a % 2 == 0)
      sum += a;
    b = a + b;
    a = b - a;
  }
  cout << sum << endl;
}
