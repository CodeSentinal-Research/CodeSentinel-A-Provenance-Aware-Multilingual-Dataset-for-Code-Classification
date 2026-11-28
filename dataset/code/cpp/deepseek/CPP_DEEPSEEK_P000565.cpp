#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

vector<pair<int, int>> getSortedMatrixCells(int rows, int cols, int rCenter, int cCenter) {
    vector<pair<int, int>> cells;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cells.push_back({i, j});
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, [](const auto& lhs, const auto& rhs) {
        return lhs.first < rhs.first;
    });

    for (auto& cell : cells) {
        int dist = abs(cell.first - rCenter) + abs(cell.second - cCenter);
        priority_queue.push({dist, cell});
    }

    vector<pair<int, int>> result;
    while (!priority_queue.empty()) {
        result.push_back(priority_queue.top().second);
        priority_queue.pop();
    }

    return result;
}

int main() {
    int rows, cols, rCenter, cCenter;
    cin >> rows >> cols >> rCenter >> cCenter;

    vector<pair<int, int>> result = getSortedMatrixCells(rows, cols, rCenter, cCenter);

    for (auto& cell : result) {
        cout << cell.first << " " << cell.second << endl;
    }

    return 0;
}

This C++ program uses a priority queue to store cells by their Manhattan distances from a starting cell. It first generates all cell coordinates, then stores them in the priority queue. Finally, it pops the cells from the priority queue in ascending order of their distances and prints them. The distances are calculated using the formula |i - rCenter| + |j - cCenter|, where i and j are the row and column indices, respectively.