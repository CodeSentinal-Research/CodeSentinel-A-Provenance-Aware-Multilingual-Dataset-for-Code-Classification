#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minSwaps(std::vector<int>& data) {
        int totalOnes = std::accumulate(data.begin(), data.end(), 0);
        if (totalOnes <= 1) return 0;

        int curOnes = 0;
        for (int i = 0; i < totalOnes; i++) curOnes += data[i];
        int maxOnes = curOnes;

        for (size_t i = totalOnes; i < data.size(); i++) {
            curOnes += data[i] - data[i - totalOnes];
            maxOnes = std::max(maxOnes, curOnes);
        }
        return totalOnes - maxOnes;
    }
};