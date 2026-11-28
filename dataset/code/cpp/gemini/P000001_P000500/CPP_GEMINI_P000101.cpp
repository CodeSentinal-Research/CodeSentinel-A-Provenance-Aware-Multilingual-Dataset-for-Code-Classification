#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << *std::max_element(arr.begin(), arr.end()) << std::endl;
    }
    return 0;
}