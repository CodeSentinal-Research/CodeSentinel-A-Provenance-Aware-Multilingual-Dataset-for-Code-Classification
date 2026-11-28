Here is the C++ code:

#include <iostream>

int rangeBitwiseAnd(int left, int right) {
    int i = 0;
    while (left && right) {
        left >>= 1;
        right >>= 1;
        i++;
    }
    return left << i;
}

int main() {
    int left, right;
    std::cout << "Enter two numbers (0 <= left < right <= 2^31 - 1): ";
    std::cin >> left >> right;
    std::cout << "Bitwise AND of numbers in the range is: " << rangeBitwiseAnd(left, right) << std::endl;
    return 0;
}

This program reads two numbers from the user, computes the bitwise AND of all numbers in the range [left, right], and prints the result. The bitwise AND of two numbers is the result of performing binary AND operation on each bit of the first number with each bit of the second number. The left shift operator (>>=) is used to divide the numbers by 2, which is equivalent to performing a binary AND operation.