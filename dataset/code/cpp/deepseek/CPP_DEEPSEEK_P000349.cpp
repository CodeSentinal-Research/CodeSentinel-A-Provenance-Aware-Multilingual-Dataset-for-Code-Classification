#include <iostream>
#include <string>

using namespace std;

void removeDuplicates(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (i < s.length()-1 && s[i] == s[i+1]) {
            s.erase(i, 2);
            i = max(i-1, 0); 
        }
    }
}

int main() {
    string s;
    cin >> s;
    while (s.length() > 0) {
        removeDuplicates(s);
        cout << s << endl;
        cin >> s;
    }
    return 0;
}