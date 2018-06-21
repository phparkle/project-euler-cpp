// Problem 70: Totient permutation
// https://projecteuler.net/problem=70

#include <array>
#include <iostream>
#include <memory>

using namespace std;

inline bool is_permutation(int a, int b) {
  array<int, 10> counta{}, countb{};
  do { ++counta[a % 10]; } while (a /= 10);
  do { ++countb[b % 10]; } while (b /= 10);
  return counta == countb;
}

int main() {
  constexpr int N_MAX = 10 * 1000 * 1000;
  unique_ptr<int[]> phi(new int[N_MAX + 1]);
  for (int i = 0; i <= N_MAX; ++i)
    phi[i] = i;
  for (int i = 2; i <= N_MAX; ++i)
    if (phi[i] == i)
      for (int j = i; j <= N_MAX; j += i)
        phi[j] -= phi[j] / i;
  int m = 0;
  for (int n = 2; n <= N_MAX; ++n) {
    if ((n - phi[n]) % 9)
      continue;
    if (m && n * phi[m] >= m * phi[n])
      continue;
    if (is_permutation(n, phi[n]))
      m = n;
  }
  cout << m << endl;
}
