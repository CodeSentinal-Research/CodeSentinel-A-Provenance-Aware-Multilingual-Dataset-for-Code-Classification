#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        if (n > 1) {
            std::cout << vals[n - 1];
            for (int i = 0; i < n - 1; i++) std::cout << " " << vals[i];
            std::cout << std::endl;
        } else if (n == 1) {
            std::cout << vals[0] << std::endl;
        }
    }
    return 0;
}