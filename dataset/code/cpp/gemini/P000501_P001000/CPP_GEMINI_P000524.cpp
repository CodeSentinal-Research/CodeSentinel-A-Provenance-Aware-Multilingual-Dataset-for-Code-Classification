#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<long long> h(n);
        for (int i = 0; i < n; i++) std::cin >> h[i];
        long long max_sum = 0;
        for (int peak = 0; peak < n; peak++) {
            long long curr_sum = h[peak];
            long long cur = h[peak];
            for (int i = peak - 1; i >= 0; i--) {
                cur = std::min(cur, h[i]);
                curr_sum += cur;
            }
            cur = h[peak];
            for (int i = peak + 1; i < n; i++) {
                cur = std::min(cur, h[i]);
                curr_sum += cur;
            }
            max_sum = std::max(max_sum, curr_sum);
        }
        std::cout << max_sum << std::endl;
    }
    return 0;
}