#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    vector<int> h(c, 0);
    int ans = 0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) h[j] = g[i][j] ? h[j]+1 : 0;
        stack<int> st;
        for(int j=0;j<=c;j++) {
            while(!st.empty() && (j==c || h[st.top()]>=h[j])) {
                int h2 = h[st.top()]; st.pop();
                int w = st.empty() ? j : j-st.top()-1;
                ans = max(ans, h2*w);
            }
            st.push(j);
        }
    }
    cout << ans << endl;
    return 0;
}
