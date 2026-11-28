#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> docs(n);
        for (int i = 0; i < n; i++) std::cin >> docs[i].first >> docs[i].second;
        std::string spec;
        std::cin >> spec;
        for (const auto& d : docs) if (d.second == spec) std::cout << d.first << "\n";
    }
    return 0;
}