#include <iostream>
using namespace std;

void printPascalTriangle(int n) {
    for (int line = 0; line < n; line++) {
        int value = 1;
        for (int i = 1; i <= line; i++) {
            cout << value << " ";
            value = value * (line - i) / i;
        }
        cout << "1";
        for (int i = 1; i < line; i++)
            cout << "   ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows you want in Pascal's Triangle: ";
    cin >> n;
    printPascalTriangle(n);
    return 0;
}