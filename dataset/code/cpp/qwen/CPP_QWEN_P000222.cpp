#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n), d(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>d[i];
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    int plat=1, ans=1, i=1, j=0;
    while(i<n && j<n) {
        if(a[i]<=d[j]) { plat++; i++; ans=max(ans,plat); }
        else { plat--; j++; }
    }
    cout << ans << endl;
    return 0;
}
