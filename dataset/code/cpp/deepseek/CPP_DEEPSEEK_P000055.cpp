Here is the C++ code that prints all uppercase English alphabets from Z to A:

#include <iostream>
using namespace std;

int main() {
    for(char c = 'Z'; c >= 'A'; c--) {
        cout << c << " ";
    }
    return 0;
}

This program uses a for loop to start at 'Z' and decrements the character variable 'c' by one each iteration until it reaches 'A'. The character variable 'c' is then printed out.