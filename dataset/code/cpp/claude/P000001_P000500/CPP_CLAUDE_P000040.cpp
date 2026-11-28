#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::pair<int, char>> getAllAscii() {
        std::vector<std::pair<int, char>> res;
        for (int i = 0; i < 128; i++) {
            res.push_back({i, static_cast<char>(i)});
        }
        return res;
    }
};
