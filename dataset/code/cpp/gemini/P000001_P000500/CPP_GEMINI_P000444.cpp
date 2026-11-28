#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int l = 0, r = n - 1;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid + 1]) r = mid;
            else l = mid + 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}