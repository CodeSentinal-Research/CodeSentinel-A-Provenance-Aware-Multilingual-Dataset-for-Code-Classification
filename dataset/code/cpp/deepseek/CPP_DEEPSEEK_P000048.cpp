#include <iostream>
using namespace std;

int main() {
    double scored, total;
    cout << "Enter the scored marks: ";
    cin >> scored;
    cout << "Enter the total marks: ";
    cin >> total;
    double percentage = (scored / total) * 100;
    cout << "Percentage: " << percentage << " %";
    return 0;
}