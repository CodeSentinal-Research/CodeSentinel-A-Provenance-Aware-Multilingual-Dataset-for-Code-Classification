#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minLength(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == s[j]) {
        while (i < j && s[i] == s[i + 1]) ++i;
        while (i < j && s[j] == s[j - 1]) --j;
        ++i;
        --j;
    }
    return max(j - i + 1, 0);
}

int main() {
    string s;
    cin >> s;
    cout << minLength(s);
    return 0;
}
In this code, we start by initializing two pointers, `i` and `j`, at the beginning and end of the string. The `while` loop continues until `i` and `j` cross each other (i.e., they point to a non-overlapping pair of characters that are the same in both directions). Inside the loop, we remove the common characters from both ends.

After the loop, we return the length of the string `s` minus `i` and `j`. If the string is empty, the function returns 0.

In the `main` function, we read the string `s` from the standard input, call the `minLength` function with `s` as the argument, and print the returned value.