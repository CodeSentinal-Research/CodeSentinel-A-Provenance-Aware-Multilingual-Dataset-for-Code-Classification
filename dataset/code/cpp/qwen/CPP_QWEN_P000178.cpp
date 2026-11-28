#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> freq;
    for (int x : a) freq[x]++;
    sort(a.begin(), a.end(), [&](int x, int y) {
        if (freq[x] != freq[y]) return freq[x] > freq[y];
        return x < y;
    });
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}
