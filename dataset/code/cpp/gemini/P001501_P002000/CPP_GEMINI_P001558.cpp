#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    std::string s;
    int k;
    if (std::cin >> s >> k) {
        if (k == 0) {
            std::cout << 0 << "\n";
            return 0;
        }
        std::unordered_map<char, int> count;
        int l = 0, maxLen = 0;

        for (size_t r = 0; r < s.length(); r++) {
            count[s[r]]++;
            while ((int)count.size() > k) {
                if (--count[s[l]] == 0) count.erase(s[l]);
                l++;
            }
            maxLen = std::max(maxLen, (int)(r - l + 1));
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}