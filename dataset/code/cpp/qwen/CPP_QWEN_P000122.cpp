#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long max_sum = LLONG_MIN, cur = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cur += x;
        if (cur > max_sum) {
            max_sum = cur;
        }
        if (cur < 0) {
            cur = 0;
        }
    }
    cout << max_sum << "\n";
    return 0;
}
