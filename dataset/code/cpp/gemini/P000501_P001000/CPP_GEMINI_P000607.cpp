#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
struct Node { int k, v, f; };
int main() {
    int cap, q;
    if (std::cin >> cap >> q) {
        std::unordered_map<int, std::list<Node>::iterator> key_map;
        std::unordered_map<int, std::list<Node>> freq_map;
        int min_freq = 0;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "put") {
                int k, v; std::cin >> k >> v;
                if (cap == 0) continue;
                if (key_map.count(k)) {
                    auto it = key_map[k];
                    int f = it->f;
                    freq_map[f].erase(it);
                    if (freq_map[f].empty() && f == min_freq) min_freq++;
                    freq_map[f + 1].push_front({k, v, f + 1});
                    key_map[k] = freq_map[f + 1].begin();
                } else {
                    if ((int)key_map.size() >= cap) {
                        auto evict = freq_map[min_freq].back();
                        key_map.erase(evict.k);
                        freq_map[min_freq].pop_back();
                    }
                    freq_map[1].push_front({k, v, 1});
                    key_map[k] = freq_map[1].begin();
                    min_freq = 1;
                }
            } else if (cmd == "get") {
                int k; std::cin >> k;
                if (key_map.count(k)) {
                    auto it = key_map[k];
                    int v = it->v, f = it->f;
                    freq_map[f].erase(it);
                    if (freq_map[f].empty() && f == min_freq) min_freq++;
                    freq_map[f + 1].push_front({k, v, f + 1});
                    key_map[k] = freq_map[f + 1].begin();
                    std::cout << v << std::endl;
                } else {
                    std::cout << -1 << std::endl;
                }
            }
        }
    }
    return 0;
}