#include <iostream>

using namespace std;

int main() {

  double number = 5.1;
  double *ptr = &number;
  double &ref = number;

  cout << "Verdien fra variable: " << number << endl;
  cout << "Verdien fra peker: " << *ptr << endl;
  cout << "Verdien from referanse: " << ref << endl;
}
