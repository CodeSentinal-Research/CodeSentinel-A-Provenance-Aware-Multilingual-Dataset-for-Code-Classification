Here is the C++ code:

#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    string binary;
    cout << "Enter a binary string: ";
    cin >> binary;
    
    unsigned int decimal = bitset<64>(binary).to_ulong();
    
    cout << "The decimal value of " << binary << " is: " << decimal << endl;
    
    return 0;
}

In this code, we're using the bitset library in C++ to convert the binary string to a decimal number. We're taking a 64-bit binary number as input and converting it to a unsigned integer (which is the equivalent of decimal). We then print out the decimal equivalent of the binary string.