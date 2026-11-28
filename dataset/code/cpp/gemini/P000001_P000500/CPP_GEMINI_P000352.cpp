#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int x;
        std::cin >> x;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) { idx = i; break; }
        }
        std::cout << idx << std::endl;
    }
    return 0;
}