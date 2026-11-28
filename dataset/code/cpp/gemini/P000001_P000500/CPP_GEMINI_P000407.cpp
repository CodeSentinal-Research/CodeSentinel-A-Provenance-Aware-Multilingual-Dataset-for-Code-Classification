#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> songs(n);
        for (int i = 0; i < n; i++) std::cin >> songs[i].first >> songs[i].second;
        std::string artist;
        std::cin >> artist;
        for (const auto& s : songs) if (s.second == artist) std::cout << s.first << "\n";
    }
    return 0;
}