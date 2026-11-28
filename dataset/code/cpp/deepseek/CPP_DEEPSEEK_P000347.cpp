#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseStr(string s, int k) {
    reverse(s.begin(), s.begin() + k);
    for (int i = k; i < s.size(); i += 2*k) {
        reverse(s.begin() + i, s.begin() + i + k);
    }
    return s;
}

int main() {
    string s;
    int k;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Enter a number: ";
    cin >> k;
    string result = reverseStr(s, k);
    cout << "Reversed string: " << result << endl;
    return 0;
}