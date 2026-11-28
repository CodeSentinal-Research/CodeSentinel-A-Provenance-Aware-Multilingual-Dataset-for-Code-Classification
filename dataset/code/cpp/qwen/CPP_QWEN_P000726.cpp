#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> generate(string s) {
    set<string> res;
    bool hasOp = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
            hasOp = true;
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            set<string> leftRes = generate(left);
            set<string> rightRes = generate(right);
            for (const string& l : leftRes) {
                for (const string& r : rightRes) {
                    res.insert("(" + l + s[i] + r + ")");
                }
            }
        }
    }
    if (!hasOp) {
        res.insert(s);
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    set<string> res = generate(s);
    for (const string& expr : res) {
        cout << expr << endl;
    }
    return 0;
}
