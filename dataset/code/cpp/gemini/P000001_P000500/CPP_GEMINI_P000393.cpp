#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> names(n);
        for (int i = 0; i < n; i++) std::cin >> names[i];
        std::string prefix;
        std::cin >> prefix;
        for (const auto& name : names) {
            if (name.rfind(prefix, 0) == 0) {
                std::cout << name << "\n";
            }
        }
    }
    return 0;
}