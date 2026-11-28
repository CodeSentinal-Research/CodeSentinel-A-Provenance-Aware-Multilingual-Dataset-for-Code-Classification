Here is the code:

#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;

    if(c >= '0' && c <= '9') {
        cout << "Not Special Symbol";
    }
    else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        cout << "Not Special Symbol";
    }
    else if(c == ' ') {
        cout << "Not Special Symbol";
    }
    else {
        cout << "Special Symbol";
    }

    return 0;
}

In this code, the user is asked to input a character. The program then checks if the character is a digit, a lowercase letter or an uppercase letter, or a space. If it's a digit or a space, it's not a special symbol, so it outputs "Not Special Symbol". If it's a lowercase letter or an uppercase letter, it's a special symbol, so it outputs "Special Symbol".