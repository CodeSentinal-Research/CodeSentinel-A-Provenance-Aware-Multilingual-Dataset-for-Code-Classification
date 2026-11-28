Here is the code:

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ' || s[i] == '\0') {
            s[i+1] = toupper(s[i+1]);
        }
    }

    cout << s;
    return 0;
}
This code reads a line of input and then iterates over each character in the string. If it encounters a space or the end of the string, it converts the character immediately following it to uppercase.