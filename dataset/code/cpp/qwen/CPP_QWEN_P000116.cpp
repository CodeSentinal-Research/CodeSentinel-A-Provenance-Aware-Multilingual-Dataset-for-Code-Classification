#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long total = (long long)n * (n + 1) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << total - sum << "\n";
    return 0;
}
