#include <string>
#include <sstream>

class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        std::stringstream ss(preorder);
        std::string node;
        int slots = 1;

        while (std::getline(ss, node, ',')) {
            slots--;
            if (slots < 0) return false;
            if (node != "#") slots += 2;
        }
        return slots == 0;
    }
};