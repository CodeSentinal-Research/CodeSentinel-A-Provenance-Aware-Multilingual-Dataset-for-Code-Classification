#include <iostream>
int main() {
    long long n;
    if (std::cin >> n) {
        long long l = 1, r = n;
        bool is_sq = false;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long long mid = l + (r - l) / 2;
            long long sq = mid * mid;
            if (sq == n) { is_sq = true; break; }
            else if (sq < n) l = mid + 1;
            else r = mid - 1;
        }
        std::cout << (is_sq ? "Yes" : "No") << std::endl;
    }
    return 0;
}