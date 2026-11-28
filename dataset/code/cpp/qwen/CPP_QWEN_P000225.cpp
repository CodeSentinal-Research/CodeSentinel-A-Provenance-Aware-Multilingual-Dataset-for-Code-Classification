#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) { cin>>a[i]; b[i]=a[i]; }
    sort(b.begin(), b.end());
    unordered_map<int, int> pos;
    for(int i=0;i<n;i++) pos[b[i]]=i;
    int ans = 0;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++) {
        if(vis[i] || pos[a[i]]==i) continue;
        int c=0, j=i;
        while(!vis[j]) { vis[j]=true; j=pos[a[j]]; c++; }
        ans += c-1;
    }
    cout << ans << endl;
    return 0;
}
