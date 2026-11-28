#include <vector>
#include <algorithm>

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        int n = dist.size();
        std::vector<int> arrival(n);
        for (int i = 0; i < n; i++) {
            arrival[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        std::sort(arrival.begin(), arrival.end());

        for (int minute = 0; minute < n; minute++) {
            if (minute >= arrival[minute]) return minute;
        }
        return n;
    }
};