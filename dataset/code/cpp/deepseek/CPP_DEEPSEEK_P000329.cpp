Here is the C++ code that solves the problem:

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> t;

    int len1 = s.length();
    int len2 = t.length();

    if (len1 > len2) {
        cout << "The extra character is: " << s[len2] << endl;
    } else if (len1 < len2) {
        cout << "The extra character is: " << t[len1] << endl;
    }

    return 0;
}

This code reads two strings from the user. It then compares the lengths of the two strings. The extra character is determined by comparing the lengths and printing the character at the correct position in the longer string. The #include <iostream> and using namespace std have been included for input and output handling, respectively.