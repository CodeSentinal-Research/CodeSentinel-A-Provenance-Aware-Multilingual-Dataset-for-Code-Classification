#include <string>
#include <unordered_set>

class Solution {
    std::string search(const std::string& s, int L) {
        std::unordered_set<std::string> seen;
        for (size_t i = 0; i + L <= s.length(); i++) {
            std::string sub = s.substr(i, L);
            if (seen.count(sub)) return sub;
            seen.insert(sub);
        }
        return "";
    }
public:
    std::string longestDupSubstring(std::string s) {
        int low = 1, high = s.length() - 1;
        std::string res = "";

        // Binary search loop to narrow down range
        while (low <= high) {
            // Calculate midpoint to prevent potential overflow
            int mid = low + (high - low) / 2;
            std::string sub = search(s, mid);
            if (!sub.empty()) {
                res = sub;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};