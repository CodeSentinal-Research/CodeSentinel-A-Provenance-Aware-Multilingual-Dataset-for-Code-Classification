#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::reverse(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            if (i > 0) std::cout << " ";
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
    return 0;
}