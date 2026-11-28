#include <vector>
#include <numeric>

class Solution {
public:
    int equilibriumPoint(std::vector<long long>& arr) {
        long long totalSum = std::accumulate(arr.begin(), arr.end(), 0LL);
        long long leftSum = 0;

        for (int i = 0; i < (int)arr.size(); i++) {
            if (leftSum == totalSum - leftSum - arr[i]) return i + 1;
            leftSum += arr[i];
        }
        return -1;
    }
};