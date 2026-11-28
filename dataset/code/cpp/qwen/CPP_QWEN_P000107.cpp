#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << (is_sorted(a.begin(), a.end()) ? "Sorted" : "Not Sorted") << "\n";
    return 0;
}
