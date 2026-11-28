#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void decToOct(int n) {
    if (n == 0)
        return;
    decToOct(n / 8);
    cout << abs(n % 8);
}

void decToHex(int n) {
    if(n == 0)
        return;
    decToHex(n / 16);
    switch(n % 16) {
        case 10: cout << 'A'; break;
        case 11: cout << 'B'; break;
        case 12: cout << 'C'; break;
        case 13: cout << 'D'; break;
        case 14: cout << 'E'; break;
        case 15: cout << 'F'; break;
        default: cout << abs(n % 16);
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << num << " in Octal: ";
    decToOct(num);
    cout << "\n" << num << " in Hexadecimal: ";
    decToHex(num);
    return 0;
}