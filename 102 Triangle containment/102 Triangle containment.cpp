// Problem 102: Triangle containment
// https://projecteuler.net/problem=102
// Answer: 228

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  ifstream fin("p102_triangles.txt");
  string buffer;
  int count = 0;
  while (getline(fin, buffer)) {
    int v[6];
    stringstream ss(buffer);
    for (int i = 0; getline(ss, buffer, ','); ++i)
      v[i] = stoi(buffer);
    int x1 = v[0] * v[3] - v[2] * v[1];
    int x2 = v[2] * v[5] - v[4] * v[3];
    int x3 = v[4] * v[1] - v[0] * v[5];
    if (x1 < 0 == x2 < 0 && x2 < 0 == x3 < 0)
      ++count;
  }
  printf("%d\n", count);
}
