#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k; std::cin >> k;
        std::unordered_map<long long, int> seen;
        seen[0] = -1;
        long long cur = 0; int max_len = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (seen.count(cur - k)) {
                max_len = std::max(max_len, i - seen[cur - k]);
            }
            if (!seen.count(cur)) seen[cur] = i;
        }
        std::cout << max_len << std::endl;
    }
    return 0;
}