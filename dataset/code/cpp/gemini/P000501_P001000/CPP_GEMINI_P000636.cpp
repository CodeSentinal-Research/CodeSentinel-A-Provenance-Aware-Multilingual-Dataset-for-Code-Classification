#include <iostream>
#include <string>
#include <vector>
int main() {
    int q;
    if (std::cin >> q) {
        std::vector<std::string> tabs;
        int cur_idx = 0;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "open") {
                std::string url; std::cin >> url;
                tabs.push_back(url);
                cur_idx = (int)tabs.size() - 1;
            } else if (cmd == "close") {
                int i; std::cin >> i;
                tabs.erase(tabs.begin() + i);
                if (cur_idx >= (int)tabs.size()) cur_idx = std::max(0, (int)tabs.size() - 1);
            } else if (cmd == "switch") {
                int i; std::cin >> i; cur_idx = i;
            } else if (cmd == "moveLeft") {
                int i; std::cin >> i;
                if (i > 0) {
                    std::swap(tabs[i], tabs[i-1]);
                    if (cur_idx == i) cur_idx = i - 1;
                    else if (cur_idx == i - 1) cur_idx = i;
                }
            } else if (cmd == "moveRight") {
                int i; std::cin >> i;
                if (i < (int)tabs.size() - 1) {
                    std::swap(tabs[i], tabs[i+1]);
                    if (cur_idx == i) cur_idx = i + 1;
                    else if (cur_idx == i + 1) cur_idx = i;
                }
            } else if (cmd == "current") {
                std::cout << (tabs.empty() ? "" : tabs[cur_idx]) << std::endl;
            }
        }
    }
    return 0;
}