#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int min_idx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i].length() < arr[min_idx].length()) min_idx = i;
        }
        std::cout << min_idx << std::endl;
    }
    return 0;
}