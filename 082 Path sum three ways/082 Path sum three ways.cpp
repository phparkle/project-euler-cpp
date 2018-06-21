#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  constexpr int N = 80;
  constexpr int INF = 1 << 30;
  vector<int> grid(N * N);
  ifstream fin("p082_matrix.txt");
  for (int i = 0; i < N; ++i) {
    string buffer;
    getline(fin, buffer);
    stringstream ss(buffer);
    for (int j = 0; j < N; ++j) {
      getline(ss, buffer, ',');
      grid[j * N + i] = stoi(buffer);
    }
  }
  set<pair<int, int>> next;
  vector<int> best(N * N, INF);
  for (int i = 0; i < N; ++i) {
    next.emplace(grid[i], i);
    best[i] = grid[i];
  }
  while (!next.empty()) {
    int x = next.begin()->second;
    next.erase(next.begin());
    int buf[3];
    int* adj = buf;
    if (x % N > 0)     *adj++ = x - 1;
    if (x % N < N - 1) *adj++ = x + 1;
    if (x + N < N * N) *adj++ = x + N;
    while (adj-- >= buf) {
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
  int min = INF;
  for (int i = (N - 1) * N; i < N * N; ++i)
    if (best[i] < min)
      min = best[i];
  cout << min << endl;
}
