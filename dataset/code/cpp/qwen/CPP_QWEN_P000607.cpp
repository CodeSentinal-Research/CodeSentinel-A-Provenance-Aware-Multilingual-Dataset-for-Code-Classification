#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;
class LFUCache {
    int cap, minFreq; unordered_map<int, pair<int, int>> m; unordered_map<int, list<int>> freqMap; unordered_map<int, list<int>::iterator> iterMap;
public:
    LFUCache(int capacity) { cap = capacity; minFreq = 0; }
    int get(int key) { if(m.find(key) == m.end()) return -1; return m[key].second; }
    void put(int key, int value) { if(cap == 0) return; m[key] = {1, value}; }
};
int main() {
    int cap, q; cin >> cap >> q; LFUCache cache(cap);
    while(q--) { string op; cin >> op; if(op == "put") { int k, v; cin >> k >> v; cache.put(k, v); } else if(op == "get") { int k; cin >> k; cout << cache.get(k) << " "; } }
    return 0;
}
