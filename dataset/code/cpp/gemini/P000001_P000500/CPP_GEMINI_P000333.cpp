#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::vector<int>> pos(26);
        for (int i = 0; i < (int)s.length(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int count = 0;
        std::string w;
        while (std::cin >> w) {
            int curr = -1;
            bool ok = true;
            for (char c : w) {
                const auto& vec = pos[c - 'a'];
                auto it = std::upper_bound(vec.begin(), vec.end(), curr);
                if (it == vec.end()) {
                    ok = false;
                    break;
                }
                curr = *it;
            }
            if (ok) count++;
        }
        std::cout << count << std::endl;
    }
    return 0;
}