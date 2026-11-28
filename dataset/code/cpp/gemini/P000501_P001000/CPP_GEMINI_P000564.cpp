#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
int main() {
    std::string begin_word, end_word;
    int n;
    if (std::cin >> begin_word >> end_word >> n) {
        std::unordered_set<std::string> word_list;
        for (int i = 0; i < n; i++) {
            std::string w; std::cin >> w;
            word_list.insert(w);
        }
        if (!word_list.count(end_word)) return 0;
        std::unordered_map<std::string, std::vector<std::vector<std::string>>> layer;
        layer[begin_word] = {{begin_word}};
        while (!layer.empty()) {
            if (layer.count(end_word)) {
                for (const auto& path : layer[end_word]) {
                    for (size_t j = 0; j < path.size(); j++) {
                        std::cout << path[j] << (j + 1 == path.size() ? "" : " ");
                    }
                    std::cout << std::endl;
                }
                return 0;
            }
            std::unordered_map<std::string, std::vector<std::vector<std::string>>> new_layer;
            for (const auto& [word, paths] : layer) {
                for (size_t i = 0; i < word.length(); i++) {
                    std::string nxt = word;
                    for (char c = 'a'; c <= 'z'; c++) {
                        nxt[i] = c;
                        if (word_list.count(nxt)) {
                            for (const auto& p : paths) {
                                auto new_p = p;
                                new_p.push_back(nxt);
                                new_layer[nxt].push_back(new_p);
                            }
                        }
                    }
                }
            }
            for (const auto& [w, _] : new_layer) word_list.erase(w);
            layer = new_layer;
        }
    }
    return 0;
}