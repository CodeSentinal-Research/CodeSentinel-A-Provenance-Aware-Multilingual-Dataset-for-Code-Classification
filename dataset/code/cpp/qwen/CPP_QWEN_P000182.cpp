#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> freq;
    for (int x : a) freq[x]++;
    int max_freq = 0, res = INT_MAX;
    for (auto &p : freq) {
        if (p.second > max_freq || (p.second == max_freq && p.first < res)) {
            max_freq = p.second;
            res = p.first;
        }
    }
    cout << res << "\n";
    return 0;
}
