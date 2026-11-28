#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main() {
    int rows, cols, r0, c0;
    if (std::cin >> rows >> cols >> r0 >> c0) {
        std::vector<std::pair<int, int>> cells;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) cells.push_back({r, c});
        }
        std::sort(cells.begin(), cells.end(), [&](const auto& a, const auto& b) {
            return (std::abs(a.first - r0) + std::abs(a.second - c0)) < (std::abs(b.first - r0) + std::abs(b.second - c0));
        });
        for (size_t i = 0; i < cells.size(); i++) {
            std::cout << "[" << cells[i].first << "," << cells[i].second << "]" << (i + 1 == cells.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}