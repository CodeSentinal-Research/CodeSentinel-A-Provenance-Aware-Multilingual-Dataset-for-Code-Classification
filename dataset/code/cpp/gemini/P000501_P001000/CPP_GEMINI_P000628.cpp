#include <iostream>
#include <string>
#include <algorithm>
int main() {
    int q;
    if (std::cin >> q) {
        std::string text = "";
        int cursor = 0;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "addText") {
                std::string s; std::cin >> s;
                text.insert(cursor, s);
                cursor += s.length();
            } else if (cmd == "deleteText") {
                int k; std::cin >> k;
                int del_cnt = std::min(k, cursor);
                text.erase(cursor - del_cnt, del_cnt);
                cursor -= del_cnt;
                std::cout << del_cnt << std::endl;
            } else if (cmd == "cursorLeft") {
                int k; std::cin >> k;
                cursor = std::max(0, cursor - k);
                int l = std::max(0, cursor - 10);
                std::cout << text.substr(l, cursor - l) << std::endl;
            } else if (cmd == "cursorRight") {
                int k; std::cin >> k;
                cursor = std::min((int)text.length(), cursor + k);
                int l = std::max(0, cursor - 10);
                std::cout << text.substr(l, cursor - l) << std::endl;
            }
        }
    }
    return 0;
}