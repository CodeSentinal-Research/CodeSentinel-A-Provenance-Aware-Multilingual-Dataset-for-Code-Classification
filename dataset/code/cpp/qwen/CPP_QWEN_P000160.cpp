#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_set<int> s;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s.count(target - a[i])) {
            found = true;
            break;
        }
        s.insert(a[i]);
    }
    cout << (found ? "Yes" : "No") << "\n";
    return 0;
}
