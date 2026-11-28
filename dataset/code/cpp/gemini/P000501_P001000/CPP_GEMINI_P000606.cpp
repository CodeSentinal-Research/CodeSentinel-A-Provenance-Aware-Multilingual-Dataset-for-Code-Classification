#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
int main() {
    int cap, q;
    if (std::cin >> cap >> q) {
        std::list<std::pair<int, int>> lru;
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
        while (q--) {
            std::string cmd; std::cin >> cmd;
            if (cmd == "put") {
                int k, v; std::cin >> k >> v;
                if (map.count(k)) {
                    lru.erase(map[k]);
                } else if ((int)lru.size() == cap) {
                    map.erase(lru.back().first);
                    lru.pop_back();
                }
                lru.push_front({k, v});
                map[k] = lru.begin();
            } else if (cmd == "get") {
                int k; std::cin >> k;
                if (map.count(k)) {
                    int v = map[k]->second;
                    lru.erase(map[k]);
                    lru.push_front({k, v});
                    map[k] = lru.begin();
                    std::cout << v << std::endl;
                } else {
                    std::cout << -1 << std::endl;
                }
            }
        }
    }
    return 0;
}