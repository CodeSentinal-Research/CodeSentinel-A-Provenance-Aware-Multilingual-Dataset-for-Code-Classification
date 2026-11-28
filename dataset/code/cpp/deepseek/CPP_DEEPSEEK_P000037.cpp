#include <iostream>
#include <string>
using namespace std;

int binaryToDecimal(string binaryString) {
    int decimal = 0, i = 0, remainder = 0;
    while(binaryString != 0) {
        remainder = binaryString % 10;
        binaryString /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

int main() {
    string binaryString;
    cout << "Enter a binary number: ";
    cin >> binaryString;
    cout << "Decimal equivalent: " << binaryToDecimal(binaryString);
    return 0;
}