#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> members(n);
        for (int i = 0; i < n; i++) std::cin >> members[i].first >> members[i].second;
        std::string curr_date;
        std::cin >> curr_date;
        for (const auto& m : members) if (m.second < curr_date) std::cout << m.first << "\n";
    }
    return 0;
}