#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << arr[n - 1];
        for (int i = 0; i < n - 1; i++) std::cout << " " << arr[i];
        std::cout << std::endl;
    }
    return 0;
}