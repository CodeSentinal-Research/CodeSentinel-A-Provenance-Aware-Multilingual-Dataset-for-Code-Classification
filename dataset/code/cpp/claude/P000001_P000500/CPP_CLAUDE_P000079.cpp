#include <vector>

class Solution {
public:
    std::vector<int> convertSeconds(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int rem = totalSeconds % 3600;
        int minutes = rem / 60;
        int seconds = rem % 60;
        return {hours, minutes, seconds};
    }
};
