#include <vector>
#include <unordered_map>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        std::unordered_map<int, int> count;
        int l = 0;

        for (size_t r = 0; r < fruits.size(); r++) {
            count[fruits[r]]++;
            if (count.size() > 2) {
                if (--count[fruits[l]] == 0) count.erase(fruits[l]);
                l++;
            }
        }
        return fruits.size() - l;
    }
};