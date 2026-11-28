#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        long long max_so_far = arr[0], curr_max = arr[0];
        for (int i = 1; i < n; i++) {
            curr_max = std::max(arr[i], curr_max + arr[i]);
            max_so_far = std::max(max_so_far, curr_max);
        }
        std::cout << max_so_far << std::endl;
    }
    return 0;
}