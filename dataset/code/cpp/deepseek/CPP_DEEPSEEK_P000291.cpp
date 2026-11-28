#include <iostream>
#include <string>

using namespace std;

bool containsPermutation(string s1, string s2) {
    if (s1.length() > s2.length())
        return false;
    
    for (int i = 0; i <= s2.length() - s1.length(); i++) {
        string sub = s2.substr(i, s1.length());
        if (sub == s1)
            return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    if (containsPermutation(s1, s2))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}