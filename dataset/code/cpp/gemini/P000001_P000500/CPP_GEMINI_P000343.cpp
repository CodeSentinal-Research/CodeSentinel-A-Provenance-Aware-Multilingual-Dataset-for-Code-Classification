#include <iostream>
#include <string>
#include <vector>
#include <cmath>

bool checkAlmostEquivalent(std::string word1, std::string word2) {
    std::vector<int> count(26, 0);
    for (char c : word1) count[c - 'a']++;
    for (char c : word2) count[c - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (std::abs(count[i]) > 3) return false;
    }
    return true;
}

int main() {
    std::string w1, w2;
    if (std::cin >> w1 >> w2) {
        std::cout << (checkAlmostEquivalent(w1, w2) ? "Yes" : "No") << std::endl;
    }
    return 0;
}