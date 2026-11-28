#include <vector>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    int maxChunksToSorted(std::vector<int>& arr) {
        int curMax = 0, chunks = 0;
        for (size_t i = 0; i < arr.size(); i++) {
            curMax = std::max(curMax, arr[i]);
            if (curMax == (int)i) chunks++;
        }
        return chunks;
    }
};