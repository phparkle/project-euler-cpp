// Problem 13: Large sum
// https://projecteuler.net/problem=13
// Answer: 5537376230

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream fin("p013_numbers.txt");
  string buffer;
  vector<int> acc(51);
  while (getline(fin, buffer)) {
    for (int i = 50; i > 0; --i) {
      acc[i] += buffer[i - 1] - '0';
      acc[i - 1] += acc[i] / 10;
      acc[i] %= 10;
    }
  }
  for (int i = 0; i < 9; ++i)
    cout << acc[i];
  cout << endl;
}
