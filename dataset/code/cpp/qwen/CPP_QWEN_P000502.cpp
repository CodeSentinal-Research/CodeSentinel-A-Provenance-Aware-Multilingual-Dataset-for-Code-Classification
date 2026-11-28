#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int solve(vector<string>& tokens) {
    stack<long long> st;
    for (string& t : tokens) {
        if (t == "+") { long long b = st.top(); st.pop(); long long a = st.top(); st.pop(); st.push(a + b); }
        else if (t == "-") { long long b = st.top(); st.pop(); long long a = st.top(); st.pop(); st.push(a - b); }
        else if (t == "*") { long long b = st.top(); st.pop(); long long a = st.top(); st.pop(); st.push(a * b); }
        else if (t == "/") { long long b = st.top(); st.pop(); long long a = st.top(); st.pop(); st.push(a / b); }
        else st.push(stoll(t));
    }
    return st.top();
}

int main() {
    int n; cin >> n;
    vector<string> tokens(n);
    for (int i = 0; i < n; i++) cin >> tokens[i];
    cout << solve(tokens) << endl;
    return 0;
}
