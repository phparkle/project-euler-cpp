// Problem 82: Path sum three ways
// https://projecteuler.net/problem=82
//
// Dynamic programming approach.

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  constexpr int N = 80;
  ifstream fin("p082_matrix.txt");
  vector<vector<int>> grid(N, vector<int>(N));
  string buffer;
  for (int i = 0; getline(fin, buffer); ++i) {
    stringstream ss(buffer);
    for (int j = 0; getline(ss, buffer, ','); ++j)
      grid[j][i] = stoi(buffer);
  }
  vector<int> best = grid[0];
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      best[j] += grid[i][j];
    for (int j = 1; j < N; ++j)
      if (best[j - 1] + grid[i][j] < best[j])
        best[j] = best[j - 1] + grid[i][j];
    for (int j = N - 2; j >= 0; --j)
      if (best[j + 1] + grid[i][j] < best[j])
        best[j] = best[j + 1] + grid[i][j];
  }
  int min = 1 << 30;
  for (int i = 0; i < N; ++i)
    if (best[i] < min)
      min = best[i];
  cout << min << endl;
}
