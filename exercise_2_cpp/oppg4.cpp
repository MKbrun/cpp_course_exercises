#include <iostream>

using namespace std;

int main() {

  // Normal int
  int a = 5;

  // Referanser må initialiseres når de deklareres
  int &b = a;

  // Denne går vel? Men kanskje ikke helt riktig?
  int *c;

  // b er ikke en variabel du kan ta adressen til
  c = &a;

  // a og b er ikke pekere
  a = b + *c;

  // Må fjerne referanse operatøren
  b = 2;

  return 0;
}
