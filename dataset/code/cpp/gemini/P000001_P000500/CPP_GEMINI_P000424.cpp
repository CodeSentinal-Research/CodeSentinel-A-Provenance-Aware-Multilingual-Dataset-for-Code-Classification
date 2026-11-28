#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> emails(n);
        std::unordered_map<std::string, int> count;
        for (int i = 0; i < n; i++) {
            std::cin >> emails[i];
            count[emails[i]]++;
        }
        std::unordered_set<std::string> seen;
        for (const auto& e : emails) {
            if (count[e] > 1 && !seen.count(e)) {
                std::cout << e << "\n";
                seen.insert(e);
            }
        }
    }
    return 0;
}