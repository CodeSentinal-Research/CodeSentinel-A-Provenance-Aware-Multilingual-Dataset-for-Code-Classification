#include <iostream>
#include <string>

using namespace std;

string reverseString(string s) {
    if(s.empty()) {
        return s;
    }
    return reverseString(s.substr(1)) + s[0];
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Reversed String: " << reverseString(s) << endl;
    return 0;
}