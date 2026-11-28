#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        long long maxP = arr[0], minP = arr[0], ans = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) std::swap(maxP, minP);
            maxP = std::max(arr[i], maxP * arr[i]);
            minP = std::min(arr[i], minP * arr[i]);
            ans = std::max(ans, maxP);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}