// Problem 10: Summation of primes
// https://projecteuler.net/problem=10
// Answer: 142913828922

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  constexpr int n = 2000000;
  vector<char> s(n >> 1);
  long long sum = 2;
  int i = 1;
  while ((i += 2) < n) {
    if (s[i >> 1]) continue;
    sum += i;
    int j = i;
    while ((j += i + i) < n)
      s[j >> 1] = true;
  }
  cout << sum << endl;
}
