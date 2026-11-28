Here is the C++ code:

#include <iostream>
using namespace std;

bool isHarshad(int n) {
    int sum = 0;
    int digit;
    while (n != 0) {
        digit = n % 10;
        sum += digit;
        n /= 10;
    }
    return (n % sum == 0);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (n <= 0 || n >= 1000000) {
        cout << "Invalid input. Please enter a positive integer between 1 and 1000000.";
        return 0;
    }
    if (isHarshad(n)) {
        cout << "Harshad" << endl;
    } else {
        cout << "Not Harshad" << endl;
    }
    return 0;
}

This program first takes an input number `n` and checks whether it is a Harshad number using the `isHarshad` function. In this function, it calculates the sum of all digits of `n` by repeatedly dividing `n` by 10 and adding the remainder to `sum`. It then checks if `n` is divisible by `sum` (i.e., if it is a Harshad number).