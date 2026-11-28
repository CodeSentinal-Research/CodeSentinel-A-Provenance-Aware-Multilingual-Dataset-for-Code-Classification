#include <iostream>
#include <vector>
#include <algorithm>
bool check(const std::vector<int>& arr, int thresh, int div) {
    long long sum = 0;
    for (int v : arr) sum += (v + div - 1) / div;
    return sum <= thresh;
}
int main() {
    int n, thresh;
    if (std::cin >> n >> thresh) {
        std::vector<int> arr(n);
        int max_v = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            if (arr[i] > max_v) max_v = arr[i];
        }
        int l = 1, r = max_v, ans = max_v;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (check(arr, thresh, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}