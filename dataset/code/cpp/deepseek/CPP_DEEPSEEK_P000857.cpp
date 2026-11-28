#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n <= 0)
        return false;
    else
        return (n & (n - 1)) == 0;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if(isPowerOfTwo(n))
        cout << n << " is a power of two.";
    else
        cout << n << " is not a power of two.";
    return 0;
}