#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int idx = abs(a[i]) - 1;
        if (a[idx] < 0) {
            res.push_back(abs(a[i]));
        } else {
            a[idx] = -a[idx];
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "\n" : " ");
    }
    return 0;
}
