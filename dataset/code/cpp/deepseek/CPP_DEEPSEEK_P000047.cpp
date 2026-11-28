#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    if (b == 0) {
        cout << "Division by zero is not allowed";
        return 0;
    }
    
    int quotient = a / b;
    int remainder = a % b;
    
    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder;
    
    return 0;
}