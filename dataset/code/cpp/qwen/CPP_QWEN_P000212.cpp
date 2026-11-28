#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int c = 0;
    for(int i=0;i<n;i++) {
        if(a[i]==0 && (i==0||a[i-1]==0) && (i==n-1||a[i+1]==0)) { a[i]=1; c++; }
    }
    cout << (c >= m ? "Yes" : "No") << endl;
    return 0;
}
