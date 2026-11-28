#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        for (int i = 0; i < n; i++) {
            std::string uname, status;
            std::cin >> uname >> status;
            std::string lower = status;
            std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (lower == "active" || lower == "true" || lower == "1" || lower == "yes" || lower == "enabled") {
                std::cout << uname << "\n";
            }
        }
    }
    return 0;
}