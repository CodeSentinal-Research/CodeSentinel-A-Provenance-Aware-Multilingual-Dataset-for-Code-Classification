#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_set<int> s(a.begin(), a.end());
    int res = 1;
    while (s.count(res)) res++;
    cout << res << "\n";
    return 0;
}
