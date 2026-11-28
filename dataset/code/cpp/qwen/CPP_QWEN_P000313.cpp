#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 0, n = s.size();
    while (i < n && s[i] == ' ') i++;
    if (i < n && (s[i] == '+' || s[i] == '-')) i++;
    bool is_num = false;
    while (i < n && isdigit(s[i])) { is_num = true; i++; }
    if (i < n && s[i] == '.') {
        i++;
        while (i < n && isdigit(s[i])) { is_num = true; i++; }
    }
    if (i < n && (s[i] == 'e' || s[i] == 'E')) {
        if (!is_num) { cout << "Invalid" << endl; return 0; }
        i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        bool is_exp = false;
        while (i < n && isdigit(s[i])) { is_exp = true; i++; }
        if (!is_exp) { cout << "Invalid" << endl; return 0; }
    }
    while (i < n && s[i] == ' ') i++;
    cout << (is_num && i == n ? "Valid" : "Invalid") << endl;
    return 0;
}
