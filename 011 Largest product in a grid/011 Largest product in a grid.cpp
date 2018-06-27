// Problem 11: Largest product in a grid
// https://projecteuler.net/problem=11
// Answer: 70600674

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream fin("p011_grid.txt");
  string buffer;
  vector<int> grid;
  grid.reserve(400);
  while (getline(fin, buffer)) {
    stringstream ss(buffer);
    while (getline(ss, buffer, ' '))
      grid.emplace_back(stoi(buffer));
  }
  int largest = 0;
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 17; ++j) {
      int product = 1;
      for (int k = 0; k < 4; ++k)
        product *= grid[20 * i + (j + k)];
      if (product > largest)
        largest = product;
    }
  }
  for (int i = 0; i < 17; ++i) {
    for (int j = 0; j < 20; ++j) {
      int product = 1;
      for (int k = 0; k < 4; ++k)
        product *= grid[20 * (i + k) + j];
      if (product > largest)
        largest = product;
    }
  }
  for (int i = 0; i < 17; ++i) {
    for (int j = 0; j < 17; ++j) {
      int product = 1;
      for (int k = 0; k < 4; ++k)
        product *= grid[20 * (i + k) + (j + k)];
      if (product > largest)
        largest = product;
    }
  }
  for (int i = 3; i < 20; ++i) {
    for (int j = 0; j < 17; ++j) {
      int product = 1;
      for (int k = 0; k < 4; ++k)
        product *= grid[20 * (i - k) + (j + k)];
      if (product > largest)
        largest = product;
    }
  }
  cout << largest << endl;
}
