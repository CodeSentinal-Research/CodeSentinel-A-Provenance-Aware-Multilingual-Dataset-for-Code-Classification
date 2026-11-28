#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int x;
        std::cin >> x;
        bool found = false;
        for (int v : arr) {
            if (v == x) { found = true; break; }
        }
        std::cout << (found ? "Found" : "Not Found") << std::endl;
    }
    return 0;
}