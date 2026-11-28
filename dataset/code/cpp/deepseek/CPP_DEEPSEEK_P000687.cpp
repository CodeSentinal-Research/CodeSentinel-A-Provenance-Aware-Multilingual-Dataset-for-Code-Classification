#include <iostream>
using namespace std;

int sumOfDigits(long long N) {
    if (N == 0) {
        return 0;
    } else {
        return (N % 10 + sumOfDigits(N / 10));
    }
}

int main() {
    long long N;
    cout << "Enter a non-negative integer: ";
    cin >> N;

    if (N < 0 || N > 1000000000000) {
        cout << "Invalid input. Please enter a non-negative integer within the range of 0 to 10^18." << endl;
        return 0;
    }

    cout << "The sum of the digits is: " << sumOfDigits(N) << endl;

    return 0;
}