#include <chrono>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  auto start = chrono::high_resolution_clock::now();
  constexpr int N = 80;
  ifstream fin("p082_matrix.txt");
  vector<int> grid(N * N);
  string buffer;
  for (int i = 0; getline(fin, buffer); ++i) {
    stringstream ss(buffer);
    for (int j = 0; getline(ss, buffer, ','); ++j)
      grid[j * N + i] = stoi(buffer);
  }
  auto stop1 = chrono::high_resolution_clock::now();
  set<pair<int, int>> next;
  vector<int> best(N * N, 1 << 30);
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
  int min = 1 << 30;
  for (int i = N * N - N; i < N * N; ++i)
    if (best[i] < min)
      min = best[i];
  auto stop2 = chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> elapsed1 = stop1 - start;
  chrono::duration<double, std::milli> elapsed2 = stop2 - stop1;
  cout << min << endl;
  cout << elapsed1.count() << endl;
  cout << elapsed2.count() << endl;
}
