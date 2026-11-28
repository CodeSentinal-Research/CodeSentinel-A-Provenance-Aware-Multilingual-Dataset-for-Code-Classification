#include <iostream>
#include <string>
#include <map>
#include <cmath>
int main() {
    int q;
    if (std::cin >> q) {
        std::map<int, int, std::greater<int>> poly;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "insert") {
                int c, e; std::cin >> c >> e;
                poly[e] += c;
                if (poly[e] == 0) poly.erase(e);
            } else if (cmd == "delete") {
                int e; std::cin >> e;
                poly.erase(e);
            } else if (cmd == "evaluate") {
                long long x; std::cin >> x;
                long long ans = 0;
                for (const auto& [e, c] : poly) {
                    ans += c * (long long)std::pow(x, e);
                }
                std::cout << ans << std::endl;
            } else if (cmd == "display") {
                if (poly.empty()) {
                    std::cout << "0\n";
                } else {
                    bool first = true;
                    for (const auto& [e, c] : poly) {
                        if (!first) std::cout << " + ";
                        if (e > 0) std::cout << c << "x^" << e;
                        else std::cout << c;
                        first = false;
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
    return 0;
}