#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<std::string, std::string>> records(n);
        for (int i = 0; i < n; i++) {
            std::cin >> records[i].first >> records[i].second;
        }
        std::string target_dept;
        std::cin >> target_dept;
        bool found = false;
        for (const auto& r : records) {
            if (r.second == target_dept) {
                std::cout << r.first << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "No Records Found" << std::endl;
        }
    }
    return 0;
}