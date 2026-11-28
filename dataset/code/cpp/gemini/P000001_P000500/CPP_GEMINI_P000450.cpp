#include <iostream>
#include <vector>
int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int l = 0, r = n - 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) l = mid + 1;
            else r = mid - 1;
        }
        std::cout << (l + k) << std::endl;
    }
    return 0;
}