#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max_zeros = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            cur++;
            max_zeros = max(max_zeros, cur);
        } else {
            cur = 0;
        }
    }
    cout << max_zeros << "\n";
    return 0;
}
