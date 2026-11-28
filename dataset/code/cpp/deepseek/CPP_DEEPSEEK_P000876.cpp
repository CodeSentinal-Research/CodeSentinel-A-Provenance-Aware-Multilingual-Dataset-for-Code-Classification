#include <iostream>
using namespace std;

int main() {
    long n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0 || n > 2147483647) {
        cout << "Invalid input. Expected 1 <= N <= 2^31 - 1";
        return 0;
    }

    unsigned int m = ~n + 1;

    cout << "The binary complement is: " << m;

    return 0;
}