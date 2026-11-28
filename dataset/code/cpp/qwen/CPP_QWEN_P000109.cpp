#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto it = find(a.begin(), a.end(), target);
    cout << (it != a.end() ? distance(a.begin(), it) : -1) << "\n";
    return 0;
}
