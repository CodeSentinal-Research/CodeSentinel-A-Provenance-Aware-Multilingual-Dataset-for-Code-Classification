#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        long long total = 0;
        for (int i = 0; i < n; i++) { std::cin >> nums[i]; total += nums[i]; }
        int p; std::cin >> p;
        int target = total % p;
        if (target == 0) { std::cout << 0 << std::endl; return 0; }
        std::unordered_map<int, int> seen;
        seen[0] = -1;
        int cur = 0, min_len = n;
        for (int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p;
            int needed = (cur - target + p) % p;
            if (seen.count(needed)) {
                min_len = std::min(min_len, i - seen[needed]);
            }
            seen[cur] = i;
        }
        std::cout << (min_len < n ? min_len : -1) << std::endl;
    }
    return 0;
}