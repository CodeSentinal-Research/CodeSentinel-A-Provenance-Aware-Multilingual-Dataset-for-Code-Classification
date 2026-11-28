#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int max_idx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i].length() > arr[max_idx].length()) max_idx = i;
        }
        std::cout << max_idx << std::endl;
    }
    return 0;
}