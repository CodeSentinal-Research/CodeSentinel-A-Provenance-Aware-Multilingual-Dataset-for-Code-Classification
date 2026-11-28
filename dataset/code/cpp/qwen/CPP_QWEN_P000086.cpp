#include <iostream>
using namespace std;

int main() {
    int units;
    cin >> units;
    double bill = 0;
    if (units <= 100) bill = units * 10;
    else if (units <= 200) bill = 1000 + (units - 100) * 15;
    else if (units <= 300) bill = 2500 + (units - 200) * 20;
    else bill = 4500 + (units - 300) * 25;
    cout << bill << endl;
    return 0;
}
