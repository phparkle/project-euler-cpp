// Problem 8: Largest product in a series
// https://projecteuler.net/problem=8
// Answer: 23514624000

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream fin("p008_series.txt");
  string buffer;
  vector<int> digits;
  digits.reserve(1000);
  while (getline(fin, buffer))
    for (char c : buffer)
      digits.emplace_back(c - '0');
  long long largest = 0;
  for (int i = 0; i + 12 < 1000; ++i) {
    long long product = 1;
    for (int j = i; j < i + 13; ++j)
      product *= digits[j];
    if (product > largest)
      largest = product;
  }
  cout << largest << endl;
}
