Here is the code snippet you are looking for:

#include <iostream>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> set;
    int maxLength = 0, i = 0, j = 0;
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
    std::cout << lengthOfLongestSubstring(s);
    return 0;
}

This code uses a sliding window approach to find the longest substring without repeating characters. The window is defined by two pointers, `i` and `j`, which represent the start and end of the current substring. The character at pointer `j` is added to the set if it's not in the set. If it is, it means the character has already been added to the substring, so the start of the substring is moved one step forward. If it's not, it is added to the set and the maximum length is updated if necessary. The search is repeated until `j` is passed the end of the string.