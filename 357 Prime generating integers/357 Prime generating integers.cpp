#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 1000;
bitset<N + 1> sieve_;
vector<int> primes_;

int main() {
  sieve_.set();
  for (int i = 2; i <= N; ++i) {
    if (sieve_[i]) {
      primes_.emplace_back(i);
      for (int j = i + i; j <= N; j += i)
        sieve_[j] = false;
    }
  }
  struct Entry {
    Entry(int n) : n_(n) {
      auto d = primes_.begin();
      while (n > 1) {
        while (n % *d == 0) {
          factors_.emplace_back(*d);
          n /= *d;
        }
        ++d;
      }
    }
    const int n_;
    vector<int> factors_;
    bool p_ = false;
  };

  vector<Entry> table;
  for (auto n : primes_)
    table.emplace_back(n - 1);

  getchar();
}
