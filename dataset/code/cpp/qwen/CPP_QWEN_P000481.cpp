#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> ops(n);
    for(int i=0; i<n; i++) cin >> ops[i];
    stack<int> st;
    for(string op : ops) {
        if(op == "C") { if(!st.empty()) st.pop(); }
        else if(op == "D") { if(!st.empty()) st.push(2*st.top()); }
        else if(op == "+") {
            int v1 = st.top(); st.pop();
            int v2 = st.top();
            st.push(v1);
            st.push(v1 + v2);
        } else {
            st.push(stoi(op));
        }
    }
    int sum = 0;
    while(!st.empty()) { sum += st.top(); st.pop(); }
    cout << sum << endl;
    return 0;
}
