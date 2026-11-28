#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        for (int i = n - 1; i >= 0; i--) {
            std::cout << vals[i] << (i == 0 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}