#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n; cin >> m >> n;
    vector<int> a(m), b(n);
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    if(m > n) swap(a, b), swap(m, n);
    int l=0, r=m;
    while(l <= r) {
        int i = (l+r)/2, j = (m+n+1)/2 - i;
        int maxL = max(i==0?INT_MIN:a[i-1], j==0?INT_MIN:b[j-1]);
        int minR = min(i==m?INT_MAX:a[i], j==n?INT_MAX:b[j]);
        if(maxL <= minR) { cout << ((m+n)%2==0 ? (maxL+minR)/2.0 : maxL) << endl; return 0; }
        if(maxL > minR) r = i-1; else l = i+1;
    }
    return 0;
}
