#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    vector<int> res;
    int i = 0, j = 0;
    while (i < pos.size() && j < neg.size()) {
        res.push_back(pos[i++]);
        res.push_back(neg[j++]);
    }
    while (i < pos.size()) res.push_back(pos[i++]);
    while (j < neg.size()) res.push_back(neg[j++]);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "\n" : " ");
    }
    return 0;
}
