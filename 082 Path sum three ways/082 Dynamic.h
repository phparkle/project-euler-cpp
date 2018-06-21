#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  auto start = chrono::high_resolution_clock::now();
  constexpr int N = 80;
  ifstream fin("p082_matrix.txt");
  vector<vector<int>> grid(N, vector<int>(N));
  string buffer;
  for (int i = 0; getline(fin, buffer); ++i) {
    stringstream ss(buffer);
    for (int j = 0; getline(ss, buffer, ','); ++j)
      grid[j][i] = stoi(buffer);
  }
  auto stop1 = chrono::high_resolution_clock::now();
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
  auto stop2 = chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> elapsed1 = stop1 - start;
  chrono::duration<double, std::milli> elapsed2 = stop2 - stop1;
  cout << min << endl;
  cout << elapsed1.count() << endl;
  cout << elapsed2.count() << endl;
}
