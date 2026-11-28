#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <climits>

long long minDiffTug = LLONG_MAX;

void backtrack(const std::vector<int>& arr, size_t idx, int count, long long curSum, long long totalSum, int halfSize) {
    if (count == halfSize) {
        long long diff = std::abs(totalSum - 2 * curSum);
        minDiffTug = std::min(minDiffTug, diff);
        return;
    }
    if (idx == arr.size()) return;

    backtrack(arr, idx + 1, count + 1, curSum + arr[idx], totalSum, halfSize);
    backtrack(arr, idx + 1, count, curSum, totalSum, halfSize);
}

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            totalSum += arr[i];
        }
        minDiffTug = LLONG_MAX;
        backtrack(arr, 0, 0, 0, totalSum, n / 2);
        std::cout << minDiffTug << "\n";
    }
    return 0;
}