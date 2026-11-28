#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        std::map<int, int> count;
        for (int card : hand) count[card]++;

        for (const auto& [card, freq] : count) {
            if (freq > 0) {
                for (int i = 1; i < groupSize; i++) {
                    if (count[card + i] < freq) return false;
                    count[card + i] -= freq;
                }
            }
        }
        return true;
    }
};