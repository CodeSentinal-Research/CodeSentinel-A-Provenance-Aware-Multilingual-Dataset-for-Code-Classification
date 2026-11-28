#include <vector>
#include <algorithm>

class Solution {
    int check(int x, const std::vector<int>& tops, const std::vector<int>& bottoms) {
        int rotA = 0, rotB = 0;
        for (size_t i = 0; i < tops.size(); i++) {
            if (tops[i] != x && bottoms[i] != x) return -1;
            else if (tops[i] != x) rotA++;
            else if (bottoms[i] != x) rotB++;
        }
        return std::min(rotA, rotB);
    }
public:
    int minDominoRotations(std::vector<int>& tops, std::vector<int>& bottoms) {
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1 || tops[0] == bottoms[0]) return rotations;
        return check(bottoms[0], tops, bottoms);
    }
};