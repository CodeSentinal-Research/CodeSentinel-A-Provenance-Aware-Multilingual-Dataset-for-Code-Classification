#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> police, thieves;
        for (int i = 0; i < n; i++) {
            char ch;
            std::cin >> ch;
            if (ch == 'P') police.push_back(i);
            else thieves.push_back(i);
        }

        size_t pIdx = 0, tIdx = 0;
        int caught = 0;
        while (pIdx < police.size() && tIdx < thieves.size()) {
            if (std::abs(police[pIdx] - thieves[tIdx]) <= k) {
                caught++;
                pIdx++;
                tIdx++;
            } else if (police[pIdx] < thieves[tIdx]) {
                pIdx++;
            } else {
                tIdx++;
            }
        }
        std::cout << caught << "\n";
    }
    return 0;
}