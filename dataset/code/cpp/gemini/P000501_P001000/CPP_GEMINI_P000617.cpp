#include <iostream>
#include <string>
#include <unordered_map>
int main() {
    int q;
    if (std::cin >> q) {
        std::unordered_map<int, int> cnt;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "add") {
                int x; std::cin >> x; cnt[x]++;
            } else if (cmd == "search") {
                int x; std::cin >> x;
                std::cout << (cnt[x] > 0 ? "true" : "false") << std::endl;
            } else if (cmd == "erase") {
                int x; std::cin >> x;
                if (cnt[x] > 0) { cnt[x]--; std::cout << "true\n"; }
                else { std::cout << "false\n"; }
            }
        }
    }
    return 0;
}