#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        std::unordered_map<int, int> map;
        map[0] = -1;
        int diff = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            diff += (arr[i] % 2 == 0) ? 1 : -1;
            if (map.count(diff)) {
                maxLen = std::max(maxLen, i - map[diff]);
            } else {
                map[diff] = i;
            }
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}