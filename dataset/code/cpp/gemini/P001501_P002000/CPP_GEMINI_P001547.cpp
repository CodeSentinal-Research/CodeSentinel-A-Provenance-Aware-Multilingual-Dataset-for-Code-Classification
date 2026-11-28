#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int curOdds = 0;
        for (int i = 0; i < k; i++) if (nums[i] % 2 != 0) curOdds++;
        int maxOdds = curOdds;

        for (int i = k; i < n; i++) {
            if (nums[i] % 2 != 0) curOdds++;
            if (nums[i - k] % 2 != 0) curOdds--;
            maxOdds = std::max(maxOdds, curOdds);
        }
        std::cout << maxOdds << "\n";
    }
    return 0;
}