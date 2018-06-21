// Problem 102: Triangle containment
// https://projecteuler.net/problem=102

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int main() {
  char filename[] = "p102_triangles.txt";
  char format[] = "%d,%d,%d,%d,%d,%d";
  FILE* file = fopen(filename, "r");
  int count = 0;
  for (int i = 0; i < 1000; ++i) {
    int a1, a2, b1, b2, c1, c2;
    fscanf(file, format, &a1, &a2, &b1, &b2, &c1, &c2);
    int x1 = a1 * b2 - a2 * b1;
    int x2 = b1 * c2 - b2 * c1;
    int x3 = c1 * a2 - c2 * a1;
    if (x1 < 0 == x2 < 0 && x2 < 0 == x3 < 0)
      ++count;
  }
  printf("%d\n", count);
}
