#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> freq;
    int distinct = 0;
    for (int i = 0; i < k; i++) {
        if (freq[a[i]] == 0) distinct++;
        freq[a[i]]++;
    }
    cout << distinct << " ";
    for (int i = k; i < n; i++) {
        freq[a[i - k]]--;
        if (freq[a[i - k]] == 0) distinct--;
        if (freq[a[i]] == 0) distinct++;
        freq[a[i]]++;
        cout << distinct << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}
