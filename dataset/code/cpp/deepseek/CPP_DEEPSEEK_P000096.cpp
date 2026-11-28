Here is the C++ code:

#include <iostream>
using namespace std;

bool isSpy(int n) {
    int sum = 0, product = 1;
    while (n) {
        int digit = n % 10;
        sum += digit;
        product *= digit;
        n /= 10;
    }
    return sum == product;
}

int main() {
    int n;
    cin >> n;
    if (isSpy(n)) {
        cout << "Spy";
    } else {
        cout << "Not Spy";
    }
    return 0;
}

This program first takes an input number, then checks if it is a spy number using the function `isSpy()`. The function `isSpy()` calculates the sum and product of the digits of the number and then compares them. If the sum is equal to the product, it means that the number is a spy number, so it prints "Spy" otherwise it prints "Not Spy".