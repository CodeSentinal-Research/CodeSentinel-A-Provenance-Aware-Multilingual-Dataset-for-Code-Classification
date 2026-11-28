#include <iostream>
#include <string>
#include <unordered_map>
int main() {
    int q;
    if (std::cin >> q) {
        std::unordered_map<std::string, int> counts;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "inc") {
                std::string k; std::cin >> k; counts[k]++;
            } else if (cmd == "dec") {
                std::string k; std::cin >> k;
                counts[k]--;
                if (counts[k] == 0) counts.erase(k);
            } else if (cmd == "getMaxKey") {
                if (counts.empty()) { std::cout << std::endl; }
                else {
                    int max_v = -1; std::string max_k = "";
                    for (const auto& [k, v] : counts) {
                        if (v > max_v) { max_v = v; max_k = k; }
                    }
                    std::cout << max_k << std::endl;
                }
            } else if (cmd == "getMinKey") {
                if (counts.empty()) { std::cout << std::endl; }
                else {
                    int min_v = 1e9; std::string min_k = "";
                    for (const auto& [k, v] : counts) {
                        if (v < min_v) { min_v = v; min_k = k; }
                    }
                    std::cout << min_k << std::endl;
                }
            }
        }
    }
    return 0;
}