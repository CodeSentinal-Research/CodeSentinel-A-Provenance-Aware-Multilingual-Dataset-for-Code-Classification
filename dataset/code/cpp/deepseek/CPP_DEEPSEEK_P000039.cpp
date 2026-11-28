#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter a printable character: ";
    cin >> c;
    cout << "The ASCII value of " << c << " is " << int(c) << endl;
    return 0;
}