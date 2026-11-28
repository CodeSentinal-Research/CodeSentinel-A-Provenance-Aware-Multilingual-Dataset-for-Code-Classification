#include <vector>
#include <algorithm>
#include <climits>

class Solution {
    int ans = INT_MAX;
    void backtrack(const std::vector<int>& cookies, size_t idx, std::vector<int>& children, int k) {
        if (idx == cookies.size()) {
            ans = std::min(ans, *std::max_element(children.begin(), children.end()));
            return;
        }
        if (*std::max_element(children.begin(), children.end()) >= ans) return;

        for (int i = 0; i < k; i++) {
            children[i] += cookies[idx];
            backtrack(cookies, idx + 1, children, k);
            children[i] -= cookies[idx];
            if (children[i] == 0) break;
        }
    }
public:
    int distributeCookies(std::vector<int>& cookies, int k) {
        std::sort(cookies.rbegin(), cookies.rend());
        std::vector<int> children(k, 0);
        backtrack(cookies, 0, children, k);
        return ans;
    }
};