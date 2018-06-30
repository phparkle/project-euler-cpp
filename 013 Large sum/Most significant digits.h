// Problem 13: Large sum
// https://projecteuler.net/problem=13
// Answer: 5537376230

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream fin("p013_numbers.txt");
  string buffer;
  long long sum = 0;
  while (getline(fin, buffer))
    sum += stoll(buffer.substr(0, 11));
  cout << to_string(sum).substr(0, 10) << endl;
}
