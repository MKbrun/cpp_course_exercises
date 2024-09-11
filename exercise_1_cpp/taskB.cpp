#include <fstream>
#include <iostream>

using namespace std;

const int length = 5;

void read_temperatures(double temperatures[], int length);

int main() {

  double below10 = 0, above20 = 0, between10_20 = 0;
  double temperatures[length];

  // Read the temperatures from file
  read_temperatures(temperatures, length);

  for (int i = 0; i < length; i++) {

    cout << "Temeratur nr " << i + 1 << ": " << temperatures[i] << endl;

    if (temperatures[i] < 10)
      below10++;
    if (temperatures[i] <= 20 && temperatures[i] >= 10)
      between10_20++;
    if (temperatures[i] > 20)
      above20++;
  }

  cout << "Antall under 10 er: " << below10 << endl;
  cout << "Antall mellom 10 og 20 er: " << between10_20 << endl;
  cout << "Antall over 20 er: " << above20 << endl;

  return 0;
}

void read_temperatures(double temperatures[], int length) {

  const char filename[] = "temp.dat";
  ifstream file;

  file.open(filename);
  if (!file) {
    cout << "File failed to open!" << endl;
    exit(EXIT_FAILURE);
  }

  double temp;

  int counter = 0;
  while (file >> temp && counter < length) {
    temperatures[counter] = temp;
    counter++;
  }

  file.close();
}
