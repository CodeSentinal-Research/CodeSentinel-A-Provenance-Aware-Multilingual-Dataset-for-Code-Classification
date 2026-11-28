#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int q; std::cin >> q;
        while (q--) {
            int l, r; std::cin >> l >> r;
            std::cout << (r - l + 1) << std::endl;
        }
    }
    return 0;
}