#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>& a, vector<int>& t, int l, int r) {
    if(l>=r) return 0;
    int m=(l+r)/2, inv=merge(a,t,l,m)+merge(a,t,m+1,r);
    int i=l, j=m+1, k=l;
    while(i<=m && j<=r) {
        if(a[i]<=a[j]) t[k++]=a[i++];
        else { t[k++]=a[j++]; inv+=m-i+1; }
    }
    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    for(int i=l;i<=r;i++) a[i]=t[i];
    return inv;
}
int main() {
    int n; cin >> n;
    vector<int> a(n), t(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout << merge(a, t, 0, n-1) << endl;
    return 0;
}
