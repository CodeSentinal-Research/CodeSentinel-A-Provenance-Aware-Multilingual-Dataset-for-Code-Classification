#include <iostream>
#include <vector>
#include <unordered_map>

long long countEqualPosNegSubarrays(const std::vector<int>& arr) {
    int prefixSum = 0;
    long long count = 0;
    std::unordered_map<int, int> freq;
    freq[0] = 1;
    for (int x : arr) {
        int val = x > 0 ? 1 : (x < 0 ? -1 : 0);
        prefixSum += val;
        if (freq.find(prefixSum) != freq.end()) {
            count += freq[prefixSum];
        }
        freq[prefixSum]++;
    }
    return count;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << countEqualPosNegSubarrays(arr) << "\n";
    }
    return 0;
}