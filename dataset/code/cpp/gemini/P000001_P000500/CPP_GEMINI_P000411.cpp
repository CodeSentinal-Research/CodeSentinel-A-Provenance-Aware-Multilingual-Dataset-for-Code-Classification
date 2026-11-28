#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::string line;
        std::getline(std::cin, line);
        std::vector<std::string> records(n);
        for (int i = 0; i < n; i++) std::getline(std::cin, records[i]);
        std::string keyword;
        std::getline(std::cin, keyword);
        for (const auto& r : records) {
            if (r.find(keyword) != std::string::npos) std::cout << r << "\n";
        }
    }
    return 0;
}