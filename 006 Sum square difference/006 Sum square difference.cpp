// Problem 6: Sum square difference
// https://projecteuler.net/problem=6
// Answer: 25164150

#include <iostream>

using namespace std;

int main() {
  int n = 100;
  int a = (n * (n + 1)) / 2;
  int b = (n * (n + 1) * (2 * n + 1)) / 6;
  cout << a * a - b << endl;
}
