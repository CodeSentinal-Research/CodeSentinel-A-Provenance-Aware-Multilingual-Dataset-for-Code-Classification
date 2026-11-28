#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool solve(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;
    for (int x : pushed) {
        st.push(x);
        while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
            st.pop();
            j++;
        }
    }
    return st.empty();
}

int main() {
    int n; cin >> n;
    vector<int> pu(n), po(n);
    for(int i = 0; i < n; i++) cin >> pu[i];
    for(int i = 0; i < n; i++) cin >> po[i];
    cout << (solve(pu, po) ? "true" : "false") << endl;
    return 0;
}
