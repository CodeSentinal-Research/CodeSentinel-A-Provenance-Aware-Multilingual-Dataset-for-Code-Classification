Here is the code for the problem:

#include <iostream>
using namespace std;

bool isArmstrong(int n) {
    int num = n;
    int length = 0;
    int temp = n;

    while (temp != 0) {
        length++;
        temp = temp / 10;
    }

    temp = n;
    int sum = 0;

    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, length);
        temp = temp / 10;
    }

    if (sum == num) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (isArmstrong(n)) {
        cout << "Armstrong" << endl;
    }
    else {
        cout << "Not Armstrong" << endl;
    }

    return 0;
}

In this code, the function `isArmstrong(int n)` checks whether a given number is an Armstrong number or not. It calculates the length (number of digits) of the given number and also calculates the sum of the Armstrong number by cubing each digit and summing them up. Then, it checks if the sum is equal to the original number. If it is, it returns true, otherwise it returns false. In the `main()` function, it takes an input number, checks if it's an Armstrong number using `isArmstrong(int n)` and prints "Armstrong" or "Not Armstrong" accordingly.