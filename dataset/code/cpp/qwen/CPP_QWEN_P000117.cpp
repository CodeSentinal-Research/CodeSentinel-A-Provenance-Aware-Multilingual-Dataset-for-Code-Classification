#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    bool dup = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s.count(x)) {
            dup = true;
        }
        s.insert(x);
    }
    cout << (dup ? "Yes" : "No") << "\n";
    return 0;
}
