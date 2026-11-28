#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    string result;
    for (char c : s) {
        if (result.empty() || c != result.back()) {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string result = removeDuplicates(s);
    cout << "Resulting string: " << result << endl;
    return 0;
}