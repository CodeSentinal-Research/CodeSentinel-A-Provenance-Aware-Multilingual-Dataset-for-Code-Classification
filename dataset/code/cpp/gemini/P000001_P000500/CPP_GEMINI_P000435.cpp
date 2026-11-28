#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        auto l = std::lower_bound(arr.begin(), arr.end(), target);
        auto r = std::upper_bound(arr.begin(), arr.end(), target);
        std::cout << (r - l) << std::endl;
    }
    return 0;
}