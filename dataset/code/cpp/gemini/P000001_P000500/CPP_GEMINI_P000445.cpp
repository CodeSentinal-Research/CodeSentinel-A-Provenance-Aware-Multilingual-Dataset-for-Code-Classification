#include <iostream>
int main() {
    int r, c, target;
    if (std::cin >> r >> c >> target) {
        bool found = false;
        for (int i = 0; i < r * c; i++) {
            int v;
            std::cin >> v;
            if (v == target) found = true;
        }
        std::cout << (found ? "Found" : "Not Found") << std::endl;
    }
    return 0;
}