#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<int> all;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            all.push_back(x);
        }
    }
    sort(all.begin(), all.end());
    int idx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << all[idx++] << (j == c - 1 ? "\n" : " ");
        }
    }
    return 0;
}
