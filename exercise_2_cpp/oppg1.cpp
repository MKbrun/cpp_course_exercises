#include <iostream>

using namespace std;

void addressesAndContent(int i, int j, int *p, int *q) {
  cout << "Assignemt A" << endl;
  cout << "Address: " << i << ", Content: " << &i << endl;
  cout << "Address: " << j << ", Content: " << &j << endl;
  cout << "Address: " << *p << ", Content: " << &p << endl;
  cout << "Address: " << *q << ", Content: " << &q << endl;
}

void variableMutation(int *p, int *q) {

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;
  cout << "Assignment B" << endl;
  cout << *p << " " << *q << endl;
}

int main() {
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  addressesAndContent(i, j, p, q);
  variableMutation(p, q);

  return 0;
}
