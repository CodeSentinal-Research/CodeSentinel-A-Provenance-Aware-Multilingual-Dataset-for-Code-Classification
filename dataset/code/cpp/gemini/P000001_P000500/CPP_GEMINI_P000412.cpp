#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> contacts(n);
        for (int i = 0; i < n; i++) std::cin >> contacts[i];
        std::string target;
        std::cin >> target;
        std::string target_low = target;
        std::transform(target_low.begin(), target_low.end(), target_low.begin(), ::tolower);
        for (const auto& c : contacts) {
            std::string c_low = c;
            std::transform(c_low.begin(), c_low.end(), c_low.begin(), ::tolower);
            if (c_low == target_low) std::cout << c << "\n";
        }
    }
    return 0;
}