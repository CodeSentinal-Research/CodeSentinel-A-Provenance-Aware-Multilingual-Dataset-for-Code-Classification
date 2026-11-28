#include <iostream>
using namespace std;

string convertToTitle(int columnNumber) {
    string result = "";
    while(columnNumber) {
        columnNumber--;
        result = char('A' + columnNumber % 26) + result;
        columnNumber /= 26;
    }
    return result;
}

int main() {
    int columnNumber;
    cout << "Enter a column number: ";
    cin >> columnNumber;
    cout << convertToTitle(columnNumber) << endl;
    return 0;
}