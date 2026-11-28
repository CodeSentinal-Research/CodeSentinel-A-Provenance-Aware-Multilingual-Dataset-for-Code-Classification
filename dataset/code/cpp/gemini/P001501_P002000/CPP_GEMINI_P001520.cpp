#include <vector>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    int maxChunksToSorted(std::vector<int>& arr) {
        int maxSeen = 0, chunks = 0;
        for (size_t i = 0; i < arr.size(); i++) {
            maxSeen = std::max(maxSeen, arr[i]);
            if (maxSeen == (int)i) chunks++;
        }
        return chunks;
    }
};