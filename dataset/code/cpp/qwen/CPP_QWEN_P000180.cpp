#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> freq;
    for (int x : a) freq[x]++;
    vector<int> res;
    for (auto &p : freq) {
        if (p.second > n / 3) res.push_back(p.first);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "\n" : " ");
    }
    return 0;
}
