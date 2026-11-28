#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> courses(n);
        for (int i = 0; i < n; i++) std::cin >> courses[i].first >> courses[i].second;
        std::string inst;
        std::cin >> inst;
        for (const auto& c : courses) if (c.second == inst) std::cout << c.first << "\n";
    }
    return 0;
}