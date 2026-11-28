#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    double sum = 0;
    for(int i=0;i<k;i++) sum += a[i];
    double ans = sum;
    for(int i=k;i<n;i++) { sum += a[i]-a[i-k]; ans = max(ans, sum); }
    cout << ans/k << endl;
    return 0;
}
