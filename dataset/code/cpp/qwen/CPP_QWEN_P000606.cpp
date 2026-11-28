#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;
class LRUCache {
    int cap; list<pair<int, int>> l; unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache(int capacity) { cap = capacity; }
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        l.splice(l.begin(), l, m[key]); return m[key]->second;
    }
    void put(int key, int value) {
        if(m.find(key) != m.end()) { l.splice(l.begin(), l, m[key]); m[key]->second = value; }
        else {
            if(l.size() == cap) { int k = l.back().first; l.pop_back(); m.erase(k); }
            l.push_front({key, value}); m[key] = l.begin();
        }
    }
};
int main() {
    int cap, q; cin >> cap >> q; LRUCache cache(cap);
    while(q--) { string op; cin >> op; if(op == "put") { int k, v; cin >> k >> v; cache.put(k, v); } else if(op == "get") { int k; cin >> k; cout << cache.get(k) << " "; } }
    return 0;
}
