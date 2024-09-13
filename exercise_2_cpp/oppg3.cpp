#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char text[5];
  char *pointer = text;
  char search_for = 'e';
  cin >> text;
  while (*pointer != search_for) {
    *pointer = search_for;
    pointer++;
  }

  // Det som kan gå galt er at det kan ende med en uendelig løkke
  // hvis search_for ikke finner "e". Det kan også gjøre til at vi kommer
  // utenfor rekkevidden av text bufferen.
}
