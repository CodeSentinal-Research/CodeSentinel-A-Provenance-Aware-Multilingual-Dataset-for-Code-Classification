#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    if (b == 0) {
        cout << "Division by zero is not possible.";
    } else {
        cout << a / b;
    }
    return 0;
}