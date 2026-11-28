#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

int main() {
    std::string s;
    int k;
    if (std::cin >> s >> k) {
        std::unordered_set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        int l = 0, vCount = 0, maxLen = 0;

        for (size_t r = 0; r < s.length(); r++) {
            if (vowels.count(s[r])) vCount++;
            while (vCount > k) {
                if (vowels.count(s[l++])) vCount--;
            }
            maxLen = std::max(maxLen, (int)(r - l + 1));
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}