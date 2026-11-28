#include <iostream>
#include <string>
#include <vector>

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::vector<int> count(26, 0);
    for (char c : magazine) count[c - 'a']++;
    for (char c : ransomNote) {
        if (--count[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    std::string r, m;
    if (std::cin >> r >> m) {
        std::cout << (canConstruct(r, m) ? "Yes" : "No") << std::endl;
    }
    return 0;
}