Here is the code:

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Before swapping, a = " << a << ", b = " << b << endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After swapping, a = " << a << ", b = " << b << endl;

    return 0;
}

This program works by using XOR (^) operation. XOR of two numbers gives a number which is different from both numbers. The XOR of two numbers a and b is (a AND b), where AND is the bitwise AND operation. 

In the first XOR operation, we are swapping a and b. a gets the value of b, and b gets the value of a ^ b. This gives us the value of a.

In the second XOR operation, we are swapping a and b. b gets the value of a ^ b, which is a ^ a, because XOR of a number with itself gives the number itself. This gives us the value of b.

In the third XOR operation, we are swapping a and b. a gets the value of a ^ b, which is b ^ b, because XOR of a number with itself gives the number itself. This gives us the value of a.

This way, we can swap the values of a and b.