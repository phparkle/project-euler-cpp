// Problem 15: Lattice paths
// https://projecteuler.net/problem=15
// Answer: 137846528820

#include <iostream>

using namespace std;

int main() {
  long long grid[21][21];
  for (int i = 0; i < 21; ++i)
    grid[0][i] = grid[i][0] = 1;
  for (int i = 1; i < 21; ++i)
    for (int j = 1; j < 21; ++j)
      grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
  cout << grid[20][20] << endl;
}
