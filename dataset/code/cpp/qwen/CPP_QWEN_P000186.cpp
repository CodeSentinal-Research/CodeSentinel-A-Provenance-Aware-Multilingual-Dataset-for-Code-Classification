#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int max_len = 0, pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            pos++;
            neg = neg > 0 ? neg + 1 : 0;
        } else if (a[i] < 0) {
            int t = pos;
            pos = neg > 0 ? neg + 1 : 0;
            neg = t + 1;
        } else {
            pos = 0;
            neg = 0;
        }
        max_len = max(max_len, pos);
    }
    cout << max_len << "\n";
    return 0;
}
