#include <iostream>
#include <vector>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int nonPos = 0;
        for (int i = 0; i < k; i++) if (nums[i] <= 0) nonPos++;
        int ans = nonPos == 0 ? 1 : 0;

        for (int i = k; i < n; i++) {
            if (nums[i] <= 0) nonPos++;
            if (nums[i - k] <= 0) nonPos--;
            if (nonPos == 0) ans++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}