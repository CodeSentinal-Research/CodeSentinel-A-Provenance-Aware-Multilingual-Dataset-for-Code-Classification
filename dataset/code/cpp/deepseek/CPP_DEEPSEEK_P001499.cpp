Here's the C++ code:

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    char c;
    cin >> s >> c;

    int i = s.find(c);
    if(i != string::npos)
        s = s.substr(0, i + 1) + reverse(s.substr(i + 1, s.length() - i - 1));

    cout << s;
    return 0;
}

This code reads a string and a character from the standard input. Then it finds the first occurrence of the character in the string, if it exists. If it does, it reverses the string from the first occurrence of the character till the end of the string. Finally, it prints the modified string.