#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int l = 0, r = n - 1, ans = n;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}