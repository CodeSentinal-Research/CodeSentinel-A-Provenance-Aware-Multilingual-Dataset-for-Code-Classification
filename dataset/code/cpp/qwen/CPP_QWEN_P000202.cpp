#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    unordered_set<int> s;
    for(int i=0;i<n;i++) { int x; cin>>x; s.insert(x); }
    int ans = 0;
    for(int x : s) {
        if(!s.count(x-1)) {
            int c = 1, cur = x;
            while(s.count(++cur)) c++;
            ans = max(ans, c);
        }
    }
    cout << ans << endl;
    return 0;
}
