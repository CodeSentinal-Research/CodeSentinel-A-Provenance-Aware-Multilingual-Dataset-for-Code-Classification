#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
struct Win { std::vector<std::string> hist; int cur; };
int main() {
    int q;
    if (std::cin >> q) {
        std::unordered_map<int, Win> wins;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "newWindow") {
                int id; std::string home;
                if (std::cin >> id >> home) { wins[id] = {{home}, 0}; }
            } else if (cmd == "visit") {
                int id; std::string url; std::cin >> id >> url;
                auto& w = wins[id];
                w.hist.resize(w.cur + 1);
                w.hist.push_back(url);
                w.cur++;
            } else if (cmd == "back") {
                int id, steps; std::cin >> id >> steps;
                auto& w = wins[id];
                w.cur = std::max(0, w.cur - steps);
                std::cout << w.hist[w.cur] << std::endl;
            } else if (cmd == "forward") {
                int id, steps; std::cin >> id >> steps;
                auto& w = wins[id];
                w.cur = std::min((int)w.hist.size() - 1, w.cur + steps);
                std::cout << w.hist[w.cur] << std::endl;
            } else if (cmd == "currentPage") {
                int id; std::cin >> id;
                std::cout << wins[id].hist[wins[id].cur] << std::endl;
            } else if (cmd == "closeWindow") {
                int id; std::cin >> id;
                wins.erase(id);
            }
        }
    }
    return 0;
}