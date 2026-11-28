#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int maxLenEqualPosNeg(const std::vector<int>& arr) {
    std::unordered_map<int, int> mp;
    mp[0] = -1;
    int prefixSum = 0;
    int maxLen = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        int val = arr[i] > 0 ? 1 : (arr[i] < 0 ? -1 : 0);
        prefixSum += val;
        if (mp.find(prefixSum) != mp.end()) {
            maxLen = std::max(maxLen, i - mp[prefixSum]);
        } else {
            mp[prefixSum] = i;
        }
    }
    return maxLen;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << maxLenEqualPosNeg(arr) << "\n";
    }
    return 0;
}