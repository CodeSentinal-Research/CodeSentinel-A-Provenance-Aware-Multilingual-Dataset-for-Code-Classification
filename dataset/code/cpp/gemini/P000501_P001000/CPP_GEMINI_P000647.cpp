#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
    int q;
    if (std::cin >> q) {
        std::vector<std::string> playlist;
        int cur = 0;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "addSong") {
                std::string title; std::cin >> title;
                playlist.push_back(title);
            } else if (cmd == "removeSong") {
                std::string title; std::cin >> title;
                auto it = std::find(playlist.begin(), playlist.end(), title);
                if (it != playlist.end()) {
                    playlist.erase(it);
                    if (cur >= (int)playlist.size()) cur = std::max(0, (int)playlist.size() - 1);
                }
            } else if (cmd == "playNext") {
                if (!playlist.empty()) {
                    cur = (cur + 1) % (int)playlist.size();
                    std::cout << playlist[cur] << std::endl;
                }
            } else if (cmd == "playPrevious") {
                if (!playlist.empty()) {
                    cur = (cur - 1 + (int)playlist.size()) % (int)playlist.size();
                    std::cout << playlist[cur] << std::endl;
                }
            } else if (cmd == "moveSong") {
                std::string title; int pos; std::cin >> title >> pos;
                auto it = std::find(playlist.begin(), playlist.end(), title);
                if (it != playlist.end()) {
                    playlist.erase(it);
                    playlist.insert(playlist.begin() + pos, title);
                }
            } else if (cmd == "currentSong") {
                std::cout << (playlist.empty() ? "" : playlist[cur]) << std::endl;
            }
        }
    }
    return 0;
}