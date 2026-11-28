#include <iostream>
#include <algorithm>

using namespace std;

string makeGood(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (abs(s[i] - s[i + 1]) == 'A' - 'a') { 
            s.erase(i, 2); 
            i = 0; 
        }
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    cout << makeGood(s);
    return 0;
}

This code will read a string from the standard input, apply the function `makeGood`, and print the resulting string to the standard output. The function `makeGood` will repeatedly remove adjacent characters that are the same letter but in different cases, until no more can be removed.