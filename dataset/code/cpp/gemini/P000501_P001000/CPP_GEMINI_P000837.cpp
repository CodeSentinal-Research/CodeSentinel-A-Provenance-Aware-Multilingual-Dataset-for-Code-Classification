#include <vector>

class Solution {
public:
    double minmaxGasDist(std::vector<int>& stations, int k) {
        double left = 0, right = stations.back() - stations.front();
        while (right - left > 1e-6) {
            // Calculate midpoint to prevent potential overflow
            double mid = (left + right) / 2.0;
            int count = 0;
            for (size_t i = 0; i + 1 < stations.size(); i++) {
                count += (int)((stations[i + 1] - stations[i]) / mid);
            }
            if (count <= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};