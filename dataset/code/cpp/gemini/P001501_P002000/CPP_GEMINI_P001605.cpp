#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        std::unordered_map<long long, int> seen;
        seen[0] = -1;
        long long curSum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            curSum += nums[i];
            if (seen.count(curSum - k)) {
                maxLen = std::max(maxLen, i - seen[curSum - k]);
            }
            if (!seen.count(curSum)) seen[curSum] = i;
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}