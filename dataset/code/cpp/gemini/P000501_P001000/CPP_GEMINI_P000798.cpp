#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::unordered_map<int, int> seen;
        seen[0] = -1;
        int cur = 0, max_len = 0;
        for (int i = 0; i < n; i++) {
            cur += (nums[i] == 1 ? 1 : -1);
            if (seen.count(cur)) {
                max_len = std::max(max_len, i - seen[cur]);
            } else {
                seen[cur] = i;
            }
        }
        std::cout << max_len << std::endl;
    }
    return 0;
}