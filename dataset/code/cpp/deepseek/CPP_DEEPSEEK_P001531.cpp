#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::string s;
    std::unordered_set<char> set;
    std::cin >> s;
    int left = 0, right = 0, maxLength = 0;
    while (right < s.size()) {
        if (set.find(s[right]) == set.end()) {
            set.insert(s[right]);
            right++;
            maxLength = std::max(maxLength, (int)set.size());
        } else {
            set.erase(s[left]);
            left++;
        }
    }
    std::cout << maxLength;
    return 0;
}