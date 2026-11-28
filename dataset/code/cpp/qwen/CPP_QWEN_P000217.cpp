#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    long long total = 0;
    for(int i=0;i<n;i++) { cin>>a[i]; total += a[i]; }
    long long left = 0;
    for(int i=0;i<n;i++) {
        if(left == total - left - a[i]) { cout << i << endl; return 0; }
        left += a[i];
    }
    cout << -1 << endl;
    return 0;
}
