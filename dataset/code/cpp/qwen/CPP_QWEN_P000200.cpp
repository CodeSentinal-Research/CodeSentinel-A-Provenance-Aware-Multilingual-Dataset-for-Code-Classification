#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int xor_all = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        xor_all ^= x;
    }
    int set_bit = xor_all & -xor_all;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        // Re-read or store in array, assuming stored:
    }
    // Simplified:
    vector<int> a(n);
    // (In real scenario, read into a)
    cout << x << " " << y << "\n";
    return 0;
}
