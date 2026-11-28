#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minCut(std::string s) {
        int n = s.length();
        std::vector<int> cuts(n);
        std::iota(cuts.begin(), cuts.end(), 0);

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                cuts[r] = (l == 0) ? 0 : std::min(cuts[r], cuts[l - 1] + 1);
                l--; r++;
            }
            l = i; r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                cuts[r] = (l == 0) ? 0 : std::min(cuts[r], cuts[l - 1] + 1);
                l--; r++;
            }
        }
        return cuts[n - 1];
    }
};