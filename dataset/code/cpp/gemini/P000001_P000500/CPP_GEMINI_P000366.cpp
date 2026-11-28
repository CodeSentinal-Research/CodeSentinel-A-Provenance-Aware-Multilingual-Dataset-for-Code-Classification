#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int max_idx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[max_idx]) max_idx = i;
        }
        std::cout << max_idx << std::endl;
    }
    return 0;
}