// Problem 4: Largest palindrome product
// https://projecteuler.net/problem=4
// Answer: 906609

#include <iostream>
#include <string>

using namespace std;

int main() {
  int max = 0;
  for (int i = 100; i <= 999; ++i) {
    for (int j = i; j <= 999; ++j) {
      string s = to_string(i * j);
      string t(s.rbegin(), s.rend());
      if (s == t && i * j > max)
        max = i * j;
    }
  }
  cout << max << endl;
}
