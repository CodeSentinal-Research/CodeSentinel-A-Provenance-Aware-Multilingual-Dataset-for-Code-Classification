#include <iostream>
#include <string>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        for (int i = 0; i < n; i++) {
            std::string dev, status;
            std::cin >> dev >> status;
            std::string lower = status;
            std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (lower == "online" || lower == "active" || lower == "true" || lower == "1" || lower == "yes") {
                std::cout << dev << "\n";
            }
        }
    }
    return 0;
}