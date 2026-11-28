#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        std::unordered_map<int, int> count;
        for (int i = 0; i < k; i++) count[nums[i]]++;
        int ans = (int)count.size() == k ? 1 : 0;

        for (int i = k; i < n; i++) {
            count[nums[i]]++;
            if (--count[nums[i - k]] == 0) count.erase(nums[i - k]);
            if ((int)count.size() == k) ans++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}