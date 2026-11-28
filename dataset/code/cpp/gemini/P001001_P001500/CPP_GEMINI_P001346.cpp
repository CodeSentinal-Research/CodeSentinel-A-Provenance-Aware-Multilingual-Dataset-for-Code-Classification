#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> grid(10);
    for (int i = 0; i < 10; i++) {
        if (std::cin >> grid[i]) {
            std::cout << grid[i] << "\n";
        }
    }
    return 0;
}