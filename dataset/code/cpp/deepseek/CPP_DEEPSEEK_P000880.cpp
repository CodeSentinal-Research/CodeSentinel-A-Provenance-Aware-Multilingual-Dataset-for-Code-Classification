#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) { 
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (isPalindrome(x)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
This program reads an integer input from the user. It then checks if the input is a palindrome by reverting the number and checking if the input is equal to the reverted number or if the last digit of the input is zero and the input is not zero.