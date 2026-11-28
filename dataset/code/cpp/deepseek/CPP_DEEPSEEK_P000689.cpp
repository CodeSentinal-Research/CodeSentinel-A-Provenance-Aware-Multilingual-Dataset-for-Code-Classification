Here is the complete code:

#include <iostream>
using namespace std;

long long productOfDigits(long long n) {
    if (n == 0) {
        return 0;
    }
    else {
        return (n % 10) * productOfDigits(n / 10);
    }
}

int main() {
    long long n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    
    if(n < 0 || n > 1000000000000) {
        cout << "Invalid input! Please enter a non-negative integer less than or equal to 10^18." << endl;
        return 0;
    }
    
    cout << "Product of digits: " << productOfDigits(n) << endl;
    return 0;
}
This program will ask the user to input a non-negative integer. It then calculates the product of the digits in the integer by recursively calling the productOfDigits function. The productOfDigits function checks if the input number is 0 and returns 0 if it is. Otherwise, it returns the product of the last digit of the number and the product of the rest of the digits (computed by calling the productOfDigits function on the integer without the last digit). This process continues until all digits have been processed.