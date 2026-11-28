#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) { int x; cin>>x; a.push_back(x); }
    sort(a.begin(), a.end());
    for(int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
