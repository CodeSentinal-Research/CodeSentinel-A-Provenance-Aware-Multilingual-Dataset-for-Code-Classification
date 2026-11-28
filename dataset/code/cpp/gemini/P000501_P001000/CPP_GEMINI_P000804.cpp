#include <iostream>
#include <vector>
#include <unordered_map>

long long countSubarraysXorK(const std::vector<int>& arr, int k) {
    int prefixXor = 0;
    long long count = 0;
    std::unordered_map<int, int> freq;
    freq[0] = 1;
    for (int num : arr) {
        prefixXor ^= num;
        if (freq.find(prefixXor ^ k) != freq.end()) {
            count += freq[prefixXor ^ k];
        }
        freq[prefixXor]++;
    }
    return count;
}

int main() {
    int n, k;
    if (std::cin >> n >> k && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << countSubarraysXorK(arr, k) << "\n";
    }
    return 0;
}