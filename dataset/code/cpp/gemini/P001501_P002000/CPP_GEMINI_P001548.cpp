#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        long long curProd = 1;
        for (int i = 0; i < k; i++) curProd *= nums[i];
        long long maxProd = curProd;

        for (int i = k; i < n; i++) {
            curProd = (curProd / nums[i - k]) * nums[i];
            maxProd = std::max(maxProd, curProd);
        }
        std::cout << maxProd << "\n";
    }
    return 0;
}