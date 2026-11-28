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
    vector<vector<int>> res(c, vector<int>(r));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << res[i][j] << (j == r - 1 ? "\n" : " ");
        }
    }
    return 0;
}
