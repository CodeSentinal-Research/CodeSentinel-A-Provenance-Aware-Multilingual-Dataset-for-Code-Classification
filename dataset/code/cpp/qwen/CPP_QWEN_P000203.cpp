#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> count(k, 0);
    for(int x : a) count[x]++;
    int ans = 0;
    for(int i=0;i<k;i++) if(count[i] > count[ans]) ans = i;
    cout << ans << endl;
    return 0;
}
