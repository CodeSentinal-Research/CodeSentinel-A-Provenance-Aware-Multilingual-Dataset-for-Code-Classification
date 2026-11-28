#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> res(n);
    int l = 0, r = n - 1, idx = 0;
    bool flag = true;
    while (l <= r) {
        if (flag) {
            res[idx++] = a[l++];
        } else {
            res[idx++] = a[r--];
        }
        flag = !flag;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}
