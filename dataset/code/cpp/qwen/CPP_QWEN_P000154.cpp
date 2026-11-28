#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0, sq_sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        sq_sum += (long long)a[i] * a[i];
    }
    long long S = (long long)n * (n + 1) / 2 - sum;
    long long Q = (long long)n * (n + 1) * (2 * n + 1) / 6 - sq_sum;
    long long rep = (Q / S + S) / 2;
    long long miss = rep - S;
    cout << miss << " " << rep << "\n";
    return 0;
}
