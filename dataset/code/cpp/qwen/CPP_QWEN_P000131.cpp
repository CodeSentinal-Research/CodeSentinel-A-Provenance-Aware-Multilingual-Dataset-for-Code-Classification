#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_from_right = a[n - 1];
    vector<int> leaders;
    leaders.push_back(a[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= max_from_right) {
            leaders.push_back(a[i]);
            max_from_right = a[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    for (int i = 0; i < leaders.size(); i++) {
        cout << leaders[i] << (i == leaders.size() - 1 ? "\n" : " ");
    }
    return 0;
}
