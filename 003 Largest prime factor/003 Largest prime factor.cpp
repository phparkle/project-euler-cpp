// Problem 3: Largest prime factor
// https://projecteuler.net/problem=3
// Answer: 6857

#include <iostream>

using namespace std;

int main() {
  long long n = 600851475143;
  long long d = 1;
  while (n != 1) {
    d += 2;
    while (n % d == 0)
      n /= d;
  }
  cout << d << endl;
}
