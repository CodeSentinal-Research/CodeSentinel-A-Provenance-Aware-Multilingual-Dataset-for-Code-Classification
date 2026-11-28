#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int l=0, r=n-1;
    while(l < r) {
        int m1 = (a[l]+a[r])/2, m2 = (b[l]+b[r])/2;
        if(m1 == m2) { cout << m1 << endl; return 0; }
        if(m1 < m2) l++; else r--;
    }
    cout << (a[l]+b[l])/2 << endl;
    return 0;
}
