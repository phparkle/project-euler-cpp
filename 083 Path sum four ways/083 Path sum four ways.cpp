// Problem 83: Path sum four ways
// https://projecteuler.net/problem=83
// Answer: 425185

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  constexpr int N = 80;
  ifstream fin("p083_matrix.txt");
  vector<int> grid(N * N);
  string buffer;
  for (int i = 0; getline(fin, buffer); ++i) {
    stringstream ss(buffer);
    for (int j = 0; getline(ss, buffer, ','); ++j)
      grid[i * N + j] = stoi(buffer);
  }
  set<pair<int, int>> next;
  vector<int> best(N * N, 1 << 30);
  next.emplace(grid[0], 0);
  best[0] = grid[0];
  while (!next.empty()) {
    int x = next.begin()->second;
    next.erase(next.begin());
    int buf[4];
    int* adj = buf;
    if (x % N > 0)     *adj++ = x - 1;
    if (x % N < N - 1) *adj++ = x + 1;
    if (x - N >= 0)    *adj++ = x - N;
    if (x + N < N * N) *adj++ = x + N;
    while (--adj >= buf) {
      int y = *adj;
      int prev = best[y];
      int curr = best[x] + grid[y];
      if (curr < prev) {
        next.erase({ prev, y });
        next.emplace(curr, y);
        best[y] = curr;
      }
    }
  }
  int min = best[N * N - 1];
  cout << min << endl;
}
