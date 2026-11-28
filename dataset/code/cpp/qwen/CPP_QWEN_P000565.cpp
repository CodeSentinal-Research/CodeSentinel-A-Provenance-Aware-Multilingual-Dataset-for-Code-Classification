#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int manhattan(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

int main() {
    int rows, cols, rCenter, cCenter;
    cin >> rows >> cols >> rCenter >> cCenter;
    vector<vector<int>> cells;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cells.push_back({r, c});
        }
    }
    sort(cells.begin(), cells.end(), [&](const vector<int>& a, const vector<int>& b) {
        int d1 = manhattan(a[0], a[1], rCenter, cCenter);
        int d2 = manhattan(b[0], b[1], rCenter, cCenter);
        if (d1 != d2) return d1 < d2;
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    for (auto& cell : cells) {
        cout << "[" << cell[0] << "," << cell[1] << "] ";
    }
    cout << endl;
    return 0;
}
