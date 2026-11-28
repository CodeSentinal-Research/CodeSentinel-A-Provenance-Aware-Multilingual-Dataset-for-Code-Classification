#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct Flight { std::string name; double price; std::string status; };
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<Flight> flights(n);
        for (int i = 0; i < n; i++) std::cin >> flights[i].name >> flights[i].price >> flights[i].status;
        double budget;
        std::cin >> budget;
        for (const auto& f : flights) {
            std::string st = f.status;
            std::transform(st.begin(), st.end(), st.begin(), ::tolower);
            if (f.price <= budget && (st == "available" || st == "true" || st == "1" || st == "yes")) {
                std::cout << f.name << "\n";
            }
        }
    }
    return 0;
}