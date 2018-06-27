// Problem 9: Special Pythagorean triplet
// https://projecteuler.net/problem=9
// Answer: 31875000

#include <iostream>

using namespace std;

int main() {
  for (int a = 1; a < 500; ++a) {
    for (int b = 1; b < 500; ++b) {
      int c = 1000 - a - b;
      if (a * a + b * b == c * c) {
        cout << a * b * c << endl;
        return 0;
      }
    }
  }
}
