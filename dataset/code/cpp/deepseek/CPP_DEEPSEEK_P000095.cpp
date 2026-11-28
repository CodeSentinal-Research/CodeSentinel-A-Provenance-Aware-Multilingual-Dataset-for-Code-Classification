#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1 || n > 1000) {
        cout << "Invalid input";
        return 0;
    }

    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    if (sum * sum == n) {
        cout << "Neon";
    } else {
        cout << "Not Neon";
    }

    return 0;
}