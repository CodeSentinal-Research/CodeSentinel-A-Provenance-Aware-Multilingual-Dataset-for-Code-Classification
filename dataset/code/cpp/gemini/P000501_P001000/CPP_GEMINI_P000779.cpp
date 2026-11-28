#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        std::vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            std::cin >> nums[i];
            pref[i + 1] = pref[i] + nums[i];
        }
        int q; std::cin >> q;
        while (q--) {
            int l, r; std::cin >> l >> r;
            std::cout << pref[r + 1] - pref[l] << std::endl;
        }
    }
    return 0;
}