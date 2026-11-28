#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> q(n);
        for (int i = 0; i < n; i++) std::cin >> q[i];
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            std::cout << q[i] << " " << q[i + half] << (i + 1 == half ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}