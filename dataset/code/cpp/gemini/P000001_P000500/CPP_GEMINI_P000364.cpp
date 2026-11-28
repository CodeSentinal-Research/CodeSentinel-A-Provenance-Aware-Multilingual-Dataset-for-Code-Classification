#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int q;
        std::cin >> q;
        while (q--) {
            int target;
            std::cin >> target;
            bool found = false;
            for (int val : arr) {
                if (val == target) { found = true; break; }
            }
            std::cout << (found ? "Found" : "Not Found") << "\n";
        }
    }
    return 0;
}