#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solve(string s) {
    vector<string> st;
    string cur = "";
    for (char c : s) {
        if (c == '(') {
            st.push_back(cur);
            cur = "";
        } else if (c == ')') {
            reverse(cur.begin(), cur.end());
            cur = st.back() + cur;
            st.pop_back();
        } else {
            cur += c;
        }
    }
    return cur;
}

int main() {
    string s;
    getline(cin, s);
    cout << solve(s) << endl;
    return 0;
}
