#include <iostream>
#include <vector>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == target) { idx = i; break; }
        }
        std::cout << idx << std::endl;
    }
    return 0;
}