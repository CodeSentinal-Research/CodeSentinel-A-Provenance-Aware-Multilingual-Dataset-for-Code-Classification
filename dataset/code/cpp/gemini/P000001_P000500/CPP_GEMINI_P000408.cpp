#include <iostream>
#include <string>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> emails(n);
        for (int i = 0; i < n; i++) std::cin >> emails[i];
        std::string domain;
        std::cin >> domain;
        if (domain[0] != '@') domain = "@" + domain;
        for (const auto& e : emails) {
            if (e.length() >= domain.length() && e.rfind(domain) == e.length() - domain.length()) {
                std::cout << e << "\n";
            }
        }
    }
    return 0;
}