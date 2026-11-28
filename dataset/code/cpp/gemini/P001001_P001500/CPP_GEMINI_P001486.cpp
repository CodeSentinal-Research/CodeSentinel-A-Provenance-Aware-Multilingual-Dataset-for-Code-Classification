#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        size_t i = 0, j = 0;
        while (i < version1.length() || j < version2.length()) {
            int num1 = 0, num2 = 0;
            while (i < version1.length() && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i++] - '0');
            }
            while (j < version2.length() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j++] - '0');
            }
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            i++;
            j++;
        }
        return 0;
    }
};