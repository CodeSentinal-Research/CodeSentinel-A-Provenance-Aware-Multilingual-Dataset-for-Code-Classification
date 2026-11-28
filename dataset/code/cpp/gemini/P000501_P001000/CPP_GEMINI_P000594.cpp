#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int k; std::cin >> k;
        k %= n;
        for (int i = 0; i < n; i++) {
            std::cout << vals[(i - k + n) % n] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}