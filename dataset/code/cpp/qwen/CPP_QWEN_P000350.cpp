#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    stack<pair<char, int>> st;
    for (char c : s) {
        if (!st.empty() && st.top().first == c) {
            st.top().second++;
            if (st.top().second == k) st.pop();
        } else {
            st.push({c, 1});
        }
    }
    string res = "";
    while (!st.empty()) {
        string part(st.top().second, st.top().first);
        res = part + res;
        st.pop();
    }
    cout << res << endl;
    return 0;
}
