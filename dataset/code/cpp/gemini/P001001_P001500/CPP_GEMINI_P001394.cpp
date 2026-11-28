#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n;
    long long k;
    if (std::cin >> n >> k) {
        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        std::unordered_map<long long, int> map;
        map[0] = -1;
        long long prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            if (map.count(prefix - k)) {
                maxLen = std::max(maxLen, i - map[prefix - k]);
            }
            if (!map.count(prefix)) {
                map[prefix] = i;
            }
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}