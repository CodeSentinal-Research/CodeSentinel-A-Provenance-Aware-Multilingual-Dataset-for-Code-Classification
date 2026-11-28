#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        std::unordered_map<long long, int> map;
        map[0] = -1;
        long long prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            if (map.count(prefix)) {
                maxLen = std::max(maxLen, i - map[prefix]);
            } else {
                map[prefix] = i;
            }
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}