#include <iostream>

using namespace std;

int find_sum(const int *table, int length) {
  int sum = 0;

  for (int i = 0; i < length; i++) {
    sum += *table;
    table++;
  }

  return sum;
}

int main() {
  const int length = 20;
  int table[length];
  int *ptr = table;

  for (int i = 0; i < 20; i++) {
    table[i] = i + 1;
  }

  cout << "Sum of first 10: " << find_sum(ptr, 10) << endl;
  ptr = &table[10];
  cout << "Sum of next 5: " << find_sum(ptr, 5) << endl;
  ptr = &table[15];
  cout << "Sum of last 5: " << find_sum(ptr, 5) << endl;

  return 0;
}
