#include <iostream>
#include <vector>
#include <algorithm>
bool canPlace(const std::vector<int>& arr, int c, int dist) {
    int count = 1, last = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] - last >= dist) {
            count++;
            last = arr[i];
            if (count >= c) return true;
        }
    }
    return count >= c;
}
int main() {
    int n, c;
    if (std::cin >> n >> c) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::sort(arr.begin(), arr.end());
        int l = 1, r = arr.back() - arr.front(), ans = 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (canPlace(arr, c, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}