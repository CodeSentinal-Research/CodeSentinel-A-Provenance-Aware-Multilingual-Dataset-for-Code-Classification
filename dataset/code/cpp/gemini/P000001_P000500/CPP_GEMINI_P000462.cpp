#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; i++) std::cin >> arr[i];
        int diff = (arr.back() - arr.front()) / (n - 1);
        for (int i = 0; i < n - 2; i++) {
            if (arr[i + 1] - arr[i] != diff) {
                std::cout << (arr[i] + diff) << std::endl;
                return 0;
            }
        }
        std::cout << (arr.back() + diff) << std::endl;
    }
    return 0;
}