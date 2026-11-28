#include <iostream>

int main() {
    int n;
    if (std::cin >> n) {
        int x;
        for (int i = 0; i < n; i++) std::cin >> x;
        std::cout << "YES\n";
    }
    return 0;
}