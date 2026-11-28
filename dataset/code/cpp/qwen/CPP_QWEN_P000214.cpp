#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) if(a[abs(a[i])-1] > 0) a[abs(a[i])-1] *= -1;
    for(int i=0;i<n;i++) if(a[i] > 0) cout << i+1 << " ";
    cout << endl;
    return 0;
}
