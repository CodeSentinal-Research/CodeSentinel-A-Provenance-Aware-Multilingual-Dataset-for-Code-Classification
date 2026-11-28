Here is the C++ code to implement an LFU cache:

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

struct Node {
    int key, val, freq;
    list<int>::iterator pos;
};

class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, Node> map;
    unordered_map<int, list<int>> freqMap;

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        int freq = map[key].freq;
        freqMap[freq].erase(map[key].pos);
        if (freqMap[freq].empty()) freqMap.erase(freq);
        map[key].freq++;
        minFreq = min(minFreq, map[key].freq);
        freqMap[map[key].freq].push_front(key);
        map[key].pos = freqMap[map[key].freq].begin();
        return map[key].val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (map.find(key) != map.end()) {
            get(key);
            map[key].val = value;
        } else {
            if (map.size() == capacity) {
                int evictKey = freqMap[minFreq].back();
                freqMap[minFreq].pop_back();
                map.erase(evictKey);
            }
            map[key] = {key, value, 1, freqMap[1].begin()};
            freqMap[1].push_front(key);
            minFreq = 1;
        }
    }
};

This code first initializes the LFU cache with a capacity. Then it provides two methods, get(key) and put(key, value), which are used to get and set the value associated with the key, respectively. The get operation returns the value of the key if the key exists in the cache, otherwise, it returns -1. The put operation inserts the key-value pair into the cache if the cache is not full, or updates the value of the key if it exists.