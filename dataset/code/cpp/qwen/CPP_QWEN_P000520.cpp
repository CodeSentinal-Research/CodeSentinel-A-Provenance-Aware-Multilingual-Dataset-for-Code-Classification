#include <iostream>
#include <string>
using namespace std;

string solve(string s) {
    string res = "";
    for (char c : s) {
        if (c == '*') {
            if (!res.empty()) res.pop_back();
        } else {
            res += c;
        }
    }
    return res;
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
