#include <iostream>

using namespace std;

const int length = 5;

double temp;

int main() {

  double below10 = 0, above20 = 0, between10_20 = 0;

  cout << "Du skal skrive inn 5 temperaturer:" << endl;

  for (int i = 0; i < length; i++) {
    cout << "Temeratur nr " << i + 1 << ": ";
    cin >> temp;

    if (temp < 10)
      below10++;
    if (temp <= 20 && temp >= 10)
      between10_20++;
    if (temp > 20)
      above20++;
  }

  cout << "Antall under 10 er: " << below10 << endl;
  cout << "Antall mellom 10 og 20 er: " << between10_20 << endl;
  cout << "Antall over 20 er: " << above20 << endl;

  return 0;
}
