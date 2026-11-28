#include <vector>
#include <string>
#include <bitset>
#include <iomanip>
#include <sstream>

class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (std::bitset<4>(h).count() + std::bitset<6>(m).count() == (size_t)turnedOn) {
                    std::ostringstream oss;
                    oss << h << ":" << std::setw(2) << std::setfill('0') << m;
                    res.push_back(oss.str());
                }
            }
        }
        return res;
    }
};