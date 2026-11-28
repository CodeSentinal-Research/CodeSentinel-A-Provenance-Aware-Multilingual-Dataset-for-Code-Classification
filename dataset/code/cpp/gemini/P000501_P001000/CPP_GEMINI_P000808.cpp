#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int maxLenEqualEvenOdd(const std::vector<int>& arr) {
    std::unordered_map<int, int> mp;
    mp[0] = -1;
    int prefix = 0;
    int maxLen = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        prefix += (arr[i] % 2 == 0 ? 1 : -1);
        if (mp.find(prefix) != mp.end()) {
            maxLen = std::max(maxLen, i - mp[prefix]);
        } else {
            mp[prefix] = i;
        }
    }
    return maxLen;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << maxLenEqualEvenOdd(arr) << "\n";
    }
    return 0;
}