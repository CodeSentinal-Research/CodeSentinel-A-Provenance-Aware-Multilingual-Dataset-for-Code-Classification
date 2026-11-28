#include <iostream>
#include <vector>
#include <algorithm>
bool canFinish(const std::vector<int>& arr, int h, long long speed) {
    long long hours = 0;
    for (int p : arr) {
        hours += (p + speed - 1) / speed;
    }
    return hours <= h;
}
int main() {
    int n, h;
    if (std::cin >> n >> h) {
        std::vector<int> arr(n);
        int max_v = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            if (arr[i] > max_v) max_v = arr[i];
        }
        long long l = 1, r = max_v, ans = max_v;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long long mid = l + (r - l) / 2;
            if (canFinish(arr, h, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}