Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

int evaluate(string ternary) {
    if (ternary.size() == 1) {
        return ternary[0] == 'T';
    }

    if (ternary[ternary.size() - 1] == '?') {
        return evaluate(ternary.substr(0, ternary.size() - 1));
    } else if (ternary[ternary.size() - 2] == '?') {
        return (ternary[ternary.size() - 3] == 'T') ? 1 : 0;
    } else {
        return (ternary[ternary.size() - 3] == 'T') ? 0 : 1;
    }
}

int main() {
    string ternary;
    cin >> ternary;
    cout << evaluate(ternary) << endl;
    return 0;
}

This program first checks if the ternary expression is a single character (either 'T' or 'F'). If so, it returns the character. 

If the ternary expression is longer, it recursively calls itself to evaluate the expression by removing the last character from the string. It then checks the last character in the string (which should be '?'). 

If the last character is '?', it makes a decision based on the characters before it in the string. If the characters before the last '?' were 'T', it returns 1, otherwise, it returns 0. 

This process repeats until the ternary expression is a single character, and then the program returns the character.