#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    set<int, greater<int>> s;
    for(int i=0;i<n;i++) { int x; cin>>x; s.insert(x); if(s.size()>3) s.erase(prev(s.end())); }
    cout << (s.size()==3 ? *prev(s.end()) : *s.begin()) << endl;
    return 0;
}
