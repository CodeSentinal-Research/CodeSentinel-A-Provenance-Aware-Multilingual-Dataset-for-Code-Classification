#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto it = unique(a.begin(), a.end());
    cout << distance(a.begin(), it) << "\n";
    return 0;
}
