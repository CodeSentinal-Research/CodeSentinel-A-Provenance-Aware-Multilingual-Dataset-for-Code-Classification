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
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += mp[target - a[i]];
        mp[a[i]]++;
    }
    cout << count << "\n";
    return 0;
}
