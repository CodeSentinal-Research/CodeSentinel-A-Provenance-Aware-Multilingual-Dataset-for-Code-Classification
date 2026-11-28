#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string s;
    if (std::cin >> s) {
        std::unordered_set<std::string> set;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                set.insert(s.substr(i, j - i));
            }
        }
        std::cout << set.size() + 1 << "\n";
    }
    return 0;
}