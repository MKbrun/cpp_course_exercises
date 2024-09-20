#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char *line = nullptr; // eller char *line = 0;
  strcpy(line, "Dette er en tekst");

  return 0;

  // Trur ikke dette vil fungere da nullptr er en definert ting man kan bruke,
  // vil det ikke være rett å bytte den ut med "Dette er en tekst" ?
}
