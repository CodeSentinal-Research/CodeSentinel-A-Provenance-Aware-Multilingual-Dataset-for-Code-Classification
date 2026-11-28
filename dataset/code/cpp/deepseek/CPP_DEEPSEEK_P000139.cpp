#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    unordered_set<int> a_set(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        if (a_set.count(b[i])) {
            cout << b[i] << " ";
            a_set.erase(b[i]);
        }
    }

    return 0;
}