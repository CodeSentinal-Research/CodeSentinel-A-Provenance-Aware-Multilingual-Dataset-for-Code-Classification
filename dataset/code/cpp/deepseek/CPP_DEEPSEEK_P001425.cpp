#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::unordered_set<std::string> cities;

    for (int i = 0; i < n; i++) {
        std::string source, dest;
        std::cin >> source >> dest;
        cities.insert(dest);
    }

    for (const auto& city : cities) {
        bool hasOutgoingPath = false;
        for (int i = 0; i < n; i++) {
            std::string source, dest;
            std::cin >> source >> dest;
            if (dest == city) {
                hasOutgoingPath = true;
                break;
            }
        }
        if (!hasOutgoingPath) {
            std::cout << city << std::endl;
            return 0;
        }
    }

    return 0;
}