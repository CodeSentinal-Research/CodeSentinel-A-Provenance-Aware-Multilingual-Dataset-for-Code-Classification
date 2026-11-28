#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    if (abs((int)s.size() - (int)t.size()) > 1) {
        cout << "No" << endl;
        return 0;
    }
    int i = 0, j = 0, diff = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] != t[j]) {
            diff++;
            if (s.size() > t.size()) i++;
            else if (t.size() > s.size()) j++;
            else { i++; j++; }
        } else { i++; j++; }
        if (diff > 1) { cout << "No" << endl; return 0; }
    }
    cout << "Yes" << endl;
    return 0;
}
