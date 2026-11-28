Here is the code for your problem. I've used a map to store the key-value pairs and a doubly linked list to store the recently used keys.

#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    int capacity;
    list<int> keys;
    unordered_map<int, list<int>::iterator> cache;
    unordered_map<int, int> value_map;

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        keys.splice(keys.begin(), keys, cache[key]);
        return value_map[key];
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            keys.splice(keys.begin(), keys, cache[key]);
            cache[key] = keys.begin();
            value_map[key] = value;
        } else {
            if (keys.size() == capacity) {
                int evictKey = keys.back();
                keys.pop_back();
                cache.erase(evictKey);
                value_map.erase(evictKey);
            }
            keys.push_front(key);
            cache[key] = keys.begin();
            value_map[key] = value;
        }
    }
};

int main() {
    int capacity, q, key, value;
    cin >> capacity >> q;
    LRUCache cache(capacity);
    for (int i = 0; i < q; i++) {
        cin >> key >> value;
        cache.put(key, value);
        cout << cache.get(key) << endl;
    }
    return 0;
}

Please note that this code assumes that the operations are provided in order and there are no duplicate keys or values in the cache. If you have more constraints, you'll need to add those checks.