#include <iostream>
#include <string>
#include <map>
int main() {
    int q;
    if (std::cin >> q) {
        std::map<std::string, std::string> d;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "put") {
                std::string k, v; std::cin >> k >> v; d[k] = v;
            } else if (cmd == "get") {
                std::string k; std::cin >> k;
                if (d.count(k)) std::cout << d[k] << std::endl;
                else std::cout << -1 << std::endl;
            } else if (cmd == "remove") {
                std::string k; std::cin >> k; d.erase(k);
            } else if (cmd == "firstKey") {
                std::cout << (d.empty() ? "" : d.begin()->first) << std::endl;
            } else if (cmd == "lastKey") {
                std::cout << (d.empty() ? "" : d.rbegin()->first) << std::endl;
            } else if (cmd == "nextKey") {
                std::string k; std::cin >> k;
                auto it = d.upper_bound(k);
                if (it != d.end()) std::cout << it->first << std::endl;
                else std::cout << std::endl;
            } else if (cmd == "previousKey") {
                std::string k; std::cin >> k;
                auto it = d.lower_bound(k);
                if (it != d.begin()) { --it; std::cout << it->first << std::endl; }
                else std::cout << std::endl;
            }
        }
    }
    return 0;
}