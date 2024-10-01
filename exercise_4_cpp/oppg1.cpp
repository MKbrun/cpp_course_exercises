#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void findAndPrint(vector<double> list, double value) {
    auto iterator = find(list.begin(), list.end(), value);

    if (iterator != list.end() ) {
        cout << "Value " << (*iterator) << " was found" << endl;
        return;
    }

     cout << "Value " << value << " was not found" << endl;    
}

int main() {
    vector<double> numbers = {5.5, 200.2, 30.3, 54.2, 40.4};
    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;
    
    numbers.emplace(numbers.begin() + 1, 99.9);

    cout << "Front: " << numbers.front() << endl;  

    findAndPrint(numbers, 54.2); //found

    return 0;
}