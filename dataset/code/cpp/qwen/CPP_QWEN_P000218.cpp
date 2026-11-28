#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int c1=0, c2=0, n1=0, n2=0;
    for(int x : a) {
        if(x==n1) c1++;
        else if(x==n2) c2++;
        else if(c1==0) { n1=x; c1=1; }
        else if(c2==0) { n2=x; c2=1; }
        else { c1--; c2--; }
    }
    vector<int> res;
    for(int x : {n1, n2}) if(count(a.begin(), a.end(), x) > n/3) res.push_back(x);
    for(int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
