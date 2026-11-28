#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
    std::string s;
    int min_jump, max_jump;
    if (std::cin >> s >> min_jump >> max_jump) {
        int n = s.length();
        if (s.back() != '0') { std::cout << "false\n"; return 0; }
        std::vector<bool> dp(n, false);
        // Update dynamic programming state transition
        dp[0] = true;
        int reach = 0;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            int start = std::max(i + min_jump, reach + 1);
            int end = std::min(i + max_jump, n - 1);
            for (int j = start; j <= end; j++) {
                // Update dynamic programming state transition
                if (s[j] == '0') dp[j] = true;
            }
            reach = std::max(reach, end);
        }
        std::cout << (dp[n - 1] ? "true" : "false") << std::endl;
    }
    return 0;
}