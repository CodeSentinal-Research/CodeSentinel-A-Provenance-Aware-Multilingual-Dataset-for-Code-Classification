#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::unordered_set<char> set;
        int left = 0, max_len = 0;
        // Expand window to the right
        for (int right = 0; right < s.length(); right++) {
            // Shrink window from the left while duplicate exists
            while (set.count(s[right])) set.erase(s[left++]);
            set.insert(s[right]);
            max_len = std::max(max_len, right - left + 1);
        }
        std::cout << max_len << std::endl;
    }
    return 0;
}