#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
    std::string home;
    int q;
    if (std::cin >> home >> q) {
        std::vector<std::string> history = {home};
        int curr = 0;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "visit") {
                std::string url; std::cin >> url;
                history.resize(curr + 1);
                history.push_back(url);
                curr++;
            } else if (cmd == "back") {
                int steps; std::cin >> steps;
                curr = std::max(0, curr - steps);
                std::cout << history[curr] << std::endl;
            } else if (cmd == "forward") {
                int steps; std::cin >> steps;
                curr = std::min((int)history.size() - 1, curr + steps);
                std::cout << history[curr] << std::endl;
            }
        }
    }
    return 0;
}