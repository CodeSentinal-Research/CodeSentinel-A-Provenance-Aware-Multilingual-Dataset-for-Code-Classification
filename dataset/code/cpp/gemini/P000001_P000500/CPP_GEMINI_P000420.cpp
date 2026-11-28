#include <iostream>
#include <string>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        for (int i = 0; i < n; i++) {
            std::string slot, status;
            std::cin >> slot >> status;
            std::string lower = status;
            std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (lower == "vacant" || lower == "available" || lower == "free" || lower == "empty" || lower == "true" || lower == "1" || lower == "yes") {
                std::cout << slot << "\n";
            }
        }
    }
    return 0;
}