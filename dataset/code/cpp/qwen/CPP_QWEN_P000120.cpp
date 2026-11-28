#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if ((i == 0 || a[i] > a[i - 1]) && (i == n - 1 || a[i] > a[i + 1])) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
