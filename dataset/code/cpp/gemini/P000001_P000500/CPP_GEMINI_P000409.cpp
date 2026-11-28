#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> users(n);
        for (int i = 0; i < n; i++) std::cin >> users[i];
        std::string prefix;
        std::cin >> prefix;
        for (const auto& u : users) if (u.rfind(prefix, 0) == 0) std::cout << u << "\n";
    }
    return 0;
}