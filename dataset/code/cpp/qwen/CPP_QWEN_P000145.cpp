#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, target;
    cin >> r >> c >> target;
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    int l = 0, right = r * c - 1;
    bool found = false;
    while (l <= right) {
        int mid = l + (right - l) / 2;
        if (mat[mid / c][mid % c] == target) {
            found = true;
            break;
        }
        if (mat[mid / c][mid % c] < target) {
            l = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << (found ? "Found" : "Not Found") << "\n";
    return 0;
}
