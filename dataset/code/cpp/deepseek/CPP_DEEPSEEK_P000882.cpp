Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

int sumOfDigits(long long N) {
    int sum = 0;
    while (N != 0) {
        sum += N % 10;
        N /= 10;
    }
    return sum;
}

int main() {
    long long N;
    cout << "Enter a non-negative integer N: ";
    cin >> N;
    if (N < 0) {
        cout << "Invalid input, please enter a non-negative integer." << endl;
        return 0;
    }
    cout << "Sum of decimal digits: " << sumOfDigits(N) << endl;
    return 0;
}

This code firstly asks the user to input a non-negative integer. If the input is negative, the code will output an error message and terminate. Otherwise, it will compute and print the sum of the decimal digits. The sumOfDigits function uses a while loop to repeatedly extract the last digit of the number (N % 10), add it to the sum, and remove the last digit from the number (N /= 10). This process is repeated until all decimal digits of the number have been processed.