#include <iostream>
#include <string>

using namespace std;

string removeAllOccurrences(string s, char c) {
    string result = "";
    for (char& ch : s) {
        if (ch != c) {
            result += ch;
        }
    }
    return result;
}

int main() {
    string s;
    char c;

    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, s);
    cout << "Enter a character to remove: ";
    cin >> c;

    s = removeAllOccurrences(s, c);

    cout << "String after removing all occurrences of " << c << " is: " << s;

    return 0;
}