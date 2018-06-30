// Problem 16: Power digit sum
// https://projecteuler.net/problem=16
// Answer: 1366

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> acc(302);
  acc[0] = 1;
  for (int i = 0; i < 1000; ++i) {
    for (auto& d : acc)
      d <<= 1;
    for (int j = 0; j < 301; ++j) {
      if (acc[j] > 9) {
        acc[j] -= 10;
        ++acc[j + 1];
      }
    }
  }
  int sum = 0;
  for (auto d : acc)
    sum += d;
  cout << sum << endl;
}
