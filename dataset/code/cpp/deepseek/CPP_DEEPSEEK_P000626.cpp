Here is a simple C++ solution for the given problem:

#include <iostream>
#include <map>
#include <queue>

using namespace std;

class AllOne {
public:
    AllOne() {}

    void inc(string key) {
        if (counts[key]._Get()) {
            counts[key].inc();
        }
        else {
            counts[key].init(1);
        }
        keys[counts[key]].push_back(key);
        countQueue.push(counts[key]);
    }

    void dec(string key) {
        if (counts[key]._Get()) {
            counts[key].dec();
            if (counts[key]._Get() == 0) {
                keys[counts[key]].pop_back();
                if (keys[counts[key]].empty()) {
                    countQueue.pop();
                }
            }
        }
    }

    string getMaxKey() {
        auto maxCount = countQueue.top();
        while (!keys[maxCount].empty()) {
            return keys[maxCount].front();
        }
        return "";
    }

    string getMinKey() {
        auto minCount = countQueue.front();
        while (!keys[minCount].empty()) {
            return keys[minCount].front();
        }
        return "";
    }

private:
    map<string, int> counts;
    map<int, queue<string>> countQueue;
    map<int, list<string>> keys;
};

int main() {
    AllOne allOne;

    allOne.inc("hello");
    allOne.inc("hello");
    cout << allOne.getMaxKey() << endl;
    allOne.dec("hello");
    cout << allOne.getMaxKey() << endl;
    allOne.dec("hello");
    cout << allOne.getMinKey() << endl;

    return 0;
}

This code implements the AllOne data structure. It uses a map for counting and a queue for ordering the keys with the same count. The count is stored in a queue to efficiently access the keys with the maximum and minimum counts in constant time.