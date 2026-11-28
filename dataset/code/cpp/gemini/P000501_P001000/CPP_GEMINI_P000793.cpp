#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k; std::cin >> k;
        std::unordered_map<int, int> counts;
        counts[0] = 1;
        int cur = 0; long long ans = 0;
        for (int x : nums) {
            cur += (x % 2 != 0 ? 1 : 0);
            if (counts.count(cur - k)) ans += counts[cur - k];
            counts[cur]++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}