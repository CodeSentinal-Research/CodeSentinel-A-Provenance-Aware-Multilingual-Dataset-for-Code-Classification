#include <iostream>
using namespace std;

// Factorial using recursion
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Fibonacci using recursion
int fibonacci(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Sum of digits using recursion
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

// Power function using recursion
int power(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

// Reverse a string using recursion
void reverseString(string &str, int start, int end) {
    if (start >= end)
        return;
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}

int main() {
    cout << "=== C++ Recursion Examples ===" << endl << endl;

    // Factorial
    int num = 5;
    cout << "Factorial of " << num << " = " << factorial(num) << endl;

    // Fibonacci
    cout << "Fibonacci sequence (first 10 terms): ";
    for (int i = 0; i < 10; i++)
        cout << fibonacci(i) << " ";
    cout << endl;

    // Sum of digits
    int number = 1234;
    cout << "Sum of digits of " << number << " = " << sumOfDigits(number) << endl;

    // Power
    cout << "2^10 = " << power(2, 10) << endl;

    // Reverse string
    string str = "Recursion";
    cout << "Original string: " << str << endl;
    reverseString(str, 0, str.length() - 1);
    cout << "Reversed string: " << str << endl;

    return 0;
}
