#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string order, s;
    if (std::cin >> order >> s) {
        std::vector<int> rank(26, 1000);
        for (size_t i = 0; i < order.length(); i++) {
            rank[order[i] - 'a'] = i;
        }
        std::sort(s.begin(), s.end(), [&](char a, char b) {
            return rank[a - 'a'] < rank[b - 'a'];
        });
        std::cout << s << std::endl;
    }
    return 0;
}