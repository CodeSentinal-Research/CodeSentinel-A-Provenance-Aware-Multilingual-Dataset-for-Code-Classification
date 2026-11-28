#include <vector>

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded) {
        int n = encoded.size() + 1;
        int totalXor = 0;
        for (int i = 1; i <= n; i++) totalXor ^= i;
        int oddXor = 0;
        for (size_t i = 1; i < encoded.size(); i += 2) oddXor ^= encoded[i];
        std::vector<int> perm(n);
        perm[0] = totalXor ^ oddXor;
        for (size_t i = 0; i < encoded.size(); i++) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }
        return perm;
    }
};