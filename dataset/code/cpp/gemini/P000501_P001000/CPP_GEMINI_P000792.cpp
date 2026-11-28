#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int goal; std::cin >> goal;
        std::unordered_map<int, int> counts;
        counts[0] = 1;
        int cur = 0; long long ans = 0;
        for (int x : nums) {
            cur += x;
            if (counts.count(cur - goal)) ans += counts[cur - goal];
            counts[cur]++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}