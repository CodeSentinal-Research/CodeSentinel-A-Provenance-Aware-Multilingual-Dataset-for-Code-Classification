#include <iostream>
#include <stack>
using namespace std;

string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;
    for (char c : s) {
        if (!st.empty() && st.top().first == c) {
            st.top().second++;
            if (st.top().second == k) st.pop();
        } else {
            st.push({c, 1});
        }
    }

    string res;
    for (auto& p : st) {
        res += string(p.second, p.first);
    }
    return res;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << removeDuplicates(s, k);
    return 0;
}