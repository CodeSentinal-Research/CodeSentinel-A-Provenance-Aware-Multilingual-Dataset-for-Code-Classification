#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int level = 0, start = 0;
        while (start < n) {
            int count = 1 << level;
            int end = std::min(n, start + count);
            for (int i = start; i < end; i++) {
                std::cout << arr[i] << (i == end - 1 ? "" : " ");
            }
            std::cout << "\n";
            start = end;
            level++;
        }
    }
    return 0;
}