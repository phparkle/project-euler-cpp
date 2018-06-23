// Problem 493: Under the rainbow
// https://projecteuler.net/problem=493
// Answer: 6.818741802

#include <array>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  array<array<double, 8>, 21> p;
  for (auto& row : p)
    row.fill(0);
  p[1][1] = 1;
  for (int n = 2; n <= 20; ++n) {
    for (int k = 1; k <= 7; ++k) {
      p[n][k] = p[n - 1][k - 1] * (70 - 10 * (k - 1))
              + p[n - 1][k] * (10 * k - (n - 1));
      p[n][k] /= 70 - (n - 1);
    }
  }
  double count = 0;
  for (int k = 2; k <= 7; ++k)
    count += k * p[20][k];
  cout << setprecision(10) << count << endl;
}
