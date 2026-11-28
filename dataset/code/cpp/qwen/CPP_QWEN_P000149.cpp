#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    int max_ones = -1, idx = 0;
    for (int i = 0; i < r; i++) {
        int ones = 0;
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 1) ones++;
        }
        if (ones > max_ones) {
            max_ones = ones;
            idx = i;
        }
    }
    cout << idx << "\n";
    return 0;
}
