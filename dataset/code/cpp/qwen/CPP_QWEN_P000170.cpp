#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 1) {
            res = a[i];
            break;
        }
    }
    cout << res << "\n";
    return 0;
}
