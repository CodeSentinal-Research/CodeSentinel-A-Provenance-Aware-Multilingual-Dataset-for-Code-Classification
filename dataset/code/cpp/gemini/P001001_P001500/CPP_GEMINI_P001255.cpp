#include <string>

class Solution {
public:
    int minAddToMakeValid(std::string s) {
        int openNeeded = 0, closeNeeded = 0;
        for (char c : s) {
            if (c == '(') {
                closeNeeded++;
            } else {
                if (closeNeeded > 0) {
                    closeNeeded--;
                } else {
                    openNeeded++;
                }
            }
        }
        return openNeeded + closeNeeded;
    }
};