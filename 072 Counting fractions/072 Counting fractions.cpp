// Problem 72: Counting fractions
// https://projecteuler.net/problem=72
// Answer: 303963552391

#include <iostream>
#include <memory>

using namespace std;

int main() {
  constexpr int n_max = 1000 * 1000;
  unique_ptr<int[]> phi(new int[n_max + 1]);
  for (int i = 0; i <= n_max; ++i)
    phi[i] = i;
  for (int i = 2; i <= n_max; ++i)
    if (phi[i] == i)
      for (int j = i; j <= n_max; j += i)
        phi[j] -= phi[j] / i;
  long long count = 0;
  for (int i = 2; i <= n_max; ++i)
    count += phi[i];
  cout << count << endl;
}
