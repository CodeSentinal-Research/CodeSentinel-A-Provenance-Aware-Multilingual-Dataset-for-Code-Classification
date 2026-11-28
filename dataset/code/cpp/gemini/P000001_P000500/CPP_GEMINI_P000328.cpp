#include <iostream>
#include <string>
#include <vector>

int firstUniqChar(std::string s) {
    std::vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (int i = 0; i < (int)s.length(); i++) {
        if (count[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::cout << firstUniqChar(s) << std::endl;
    }
    return 0;
}