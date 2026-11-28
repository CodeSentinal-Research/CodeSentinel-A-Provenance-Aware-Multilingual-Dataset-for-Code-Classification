#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdint>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, digit = 0;
        for (const auto& c : abbr) {
            if (isdigit(c)) {
                if (digit == 0 && c == '0') {
                    return false;
                } 
                digit *= 10;
                digit += c - '0';
            } else {
                if (digit) {
                    i += digit;
                    digit = 0;
                }
                if (i >= word.length() || word[i++] != c) {
                    return false;
                }
            }
        }
        if (digit) {
            i += digit;
        }
        return i == word.length();
    }
};
