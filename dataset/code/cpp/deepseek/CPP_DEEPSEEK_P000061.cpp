#include <iostream>
using namespace std;

int countOddDigits(int n) {
    int count = 0;
    while (n) {
        int digit = n % 10;
        if (digit % 2 == 1) {
            count++;
        }
        n /= 10;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    if (n < 0 || n > 1000000000) {
        cout << "Invalid input. Please enter a non-negative integer within the range.";
        return 0;
    }
    cout << "Count of odd digits: " << countOddDigits(n);
    return 0;
}