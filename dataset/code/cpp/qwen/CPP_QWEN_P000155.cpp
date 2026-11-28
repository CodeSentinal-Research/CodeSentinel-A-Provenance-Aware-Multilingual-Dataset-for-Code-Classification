#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max_ones = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            cur++;
            max_ones = max(max_ones, cur);
        } else {
            cur = 0;
        }
    }
    cout << max_ones << "\n";
    return 0;
}
