#include <iostream>
#include <vector>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int l = 0, r = n - 1, idx = -1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) { idx = mid; break; }
            if (arr[l] <= arr[mid]) {
                if (arr[l] <= target && target < arr[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (arr[mid] < target && target <= arr[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        std::cout << idx << std::endl;
    }
    return 0;
}