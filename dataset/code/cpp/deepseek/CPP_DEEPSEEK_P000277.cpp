#include <iostream>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> set;
    int maxLength = 0;
    int i = 0, j = 0;
    while (i < s.size() && j < s.size()) {
        if (set.find(s[j]) == set.end()) {
            set.insert(s[j++]);
            maxLength = std::max(maxLength, j - i);
        } else {
            set.erase(s[i++]);
        }
    }
    return maxLength;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << lengthOfLongestSubstring(s) << std::endl;
    return 0;
}