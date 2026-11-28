#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        auto l = std::lower_bound(arr.begin(), arr.end(), target);
        if (l != arr.end() && *l == target) {
            auto r = std::upper_bound(arr.begin(), arr.end(), target);
            std::cout << (l - arr.begin()) << " " << (r - arr.begin() - 1) << std::endl;
        } else {
            std::cout << "-1 -1" << std::endl;
        }
    }
    return 0;
}