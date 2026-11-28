#include <iostream>
#include <string>
#include <vector>
int main() {
    int q;
    if (std::cin >> q) {
        std::vector<std::string> history = {""};
        int cur = 0;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "type") {
                std::string s; std::cin >> s;
                history.resize(cur + 1);
                history.push_back(history.back() + s);
                cur++;
            } else if (cmd == "undo") {
                if (cur > 0) cur--;
            } else if (cmd == "redo") {
                if (cur + 1 < (int)history.size()) cur++;
            } else if (cmd == "print") {
                std::cout << history[cur] << std::endl;
            }
        }
    }
    return 0;
}