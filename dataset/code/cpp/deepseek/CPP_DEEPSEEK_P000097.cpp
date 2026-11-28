#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
    if (n < 10 && n > 0) {
        cout << "Not Duck";
    }
    else {
        cout << "Duck";
    }
    return 0;
}