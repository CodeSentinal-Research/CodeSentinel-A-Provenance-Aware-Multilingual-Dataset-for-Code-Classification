#include <iostream>
#include <vector>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int nonInc = 0;
        for (int i = 0; i < k - 1; i++) if (nums[i] >= nums[i + 1]) nonInc++;
        int ans = nonInc == 0 ? 1 : 0;

        for (int i = k; i < n; i++) {
            if (nums[i - 1] >= nums[i]) nonInc++;
            if (nums[i - k] >= nums[i - k + 1]) nonInc--;
            if (nonInc == 0) ans++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}