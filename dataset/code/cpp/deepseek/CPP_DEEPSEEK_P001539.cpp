Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int countVowelSubstrings(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            if (i > 0 && s[i-1] != s[i]) {
                count++;
            } else {
                count++;
            }
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << countVowelSubstrings(s) << endl;
    return 0;
}

In this code, the `countVowelSubstrings` function iterates through each character in the input string. It checks if the character is a vowel and if the previous character is not the same as the current character. If both conditions are true, it increments the count. The total count is then returned.

In the `main` function, the string is read from the standard input, and the count of the vowel substrings is printed.