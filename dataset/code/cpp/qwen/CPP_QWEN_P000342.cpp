#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            res += s[i - 1] + (s[i] - '0');
        } else {
            res += s[i];
        }
    }
    cout << res << endl;
    return 0;
}
