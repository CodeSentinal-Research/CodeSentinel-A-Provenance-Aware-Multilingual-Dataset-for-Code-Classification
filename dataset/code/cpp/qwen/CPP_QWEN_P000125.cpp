#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.count(target - a[i])) {
            cout << mp[target - a[i]] << " " << i << "\n";
            return 0;
        }
        mp[a[i]] = i;
    }
    return 0;
}
