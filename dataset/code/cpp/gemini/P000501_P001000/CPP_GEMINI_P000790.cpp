#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k; std::cin >> k;
        std::unordered_map<int, int> seen;
        seen[0] = -1;
        int cur = 0;
        bool ans = false;
        for (int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % k;
            if (seen.count(cur)) {
                if (i - seen[cur] >= 2) { ans = true; break; }
            } else {
                seen[cur] = i;
            }
        }
        std::cout << (ans ? "true" : "false") << std::endl;
    }
    return 0;
}