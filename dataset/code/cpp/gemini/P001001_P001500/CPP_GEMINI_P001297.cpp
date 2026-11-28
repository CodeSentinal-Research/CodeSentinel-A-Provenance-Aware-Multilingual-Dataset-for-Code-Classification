#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<long long> arr(n);
        long long baseSum = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            baseSum += (long long)i * arr[i];
        }

        long long maxSum = baseSum;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long gain = (long long)(j - i) * arr[i] + (long long)(i - j) * arr[j];
                maxSum = std::max(maxSum, baseSum + gain);
            }
        }
        std::cout << maxSum << "\n";
    }
    return 0;
}