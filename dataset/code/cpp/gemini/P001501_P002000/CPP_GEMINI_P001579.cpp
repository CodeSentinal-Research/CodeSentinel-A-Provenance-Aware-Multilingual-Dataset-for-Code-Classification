#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int curNegs = 0;
        for (int i = 0; i < k; i++) if (nums[i] < 0) curNegs++;
        int maxNegs = curNegs;

        for (int i = k; i < n; i++) {
            if (nums[i] < 0) curNegs++;
            if (nums[i - k] < 0) curNegs--;
            maxNegs = std::max(maxNegs, curNegs);
        }
        std::cout << maxNegs << "\n";
    }
    return 0;
}