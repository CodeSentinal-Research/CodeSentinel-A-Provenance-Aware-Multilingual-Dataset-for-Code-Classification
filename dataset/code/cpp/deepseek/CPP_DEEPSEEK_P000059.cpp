#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    
    long long product = 1;
    while(n != 0) {
        product *= (n % 10);
        n /= 10;
    }
    
    cout << "Product of digits: " << product;
    return 0;
}