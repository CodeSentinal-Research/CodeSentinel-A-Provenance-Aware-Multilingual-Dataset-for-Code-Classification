#include <set>

class SmallestInfiniteSet {
    int cur;
    std::set<int> added;
public:
    SmallestInfiniteSet() : cur(1) {}

    int popSmallest() {
        if (!added.empty()) {
            int val = *added.begin();
            added.erase(added.begin());
            return val;
        }
        return cur++;
    }

    void addBack(int num) {
        if (num < cur) {
            added.insert(num);
        }
    }
};