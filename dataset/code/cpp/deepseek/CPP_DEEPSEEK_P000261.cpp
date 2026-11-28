Here is the C++ code for the problem:

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        } else if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
    cout << s;
    return 0;
}

This code will take a string as input and then iterate over each character in the string. If the character is a lowercase letter, it will be converted to an uppercase letter. If the character is an uppercase letter, it will be converted to a lowercase letter. The result is then printed out.