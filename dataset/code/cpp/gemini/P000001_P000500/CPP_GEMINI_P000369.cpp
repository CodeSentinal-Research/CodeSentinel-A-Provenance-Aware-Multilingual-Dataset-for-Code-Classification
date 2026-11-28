#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::string line;
        std::getline(std::cin, line);
        int idx = -1;
        for (int i = 0; i < n; i++) {
            std::getline(std::cin, line);
            if (line.empty() && idx == -1) idx = i;
        }
        std::cout << idx << std::endl;
    }
    return 0;
}