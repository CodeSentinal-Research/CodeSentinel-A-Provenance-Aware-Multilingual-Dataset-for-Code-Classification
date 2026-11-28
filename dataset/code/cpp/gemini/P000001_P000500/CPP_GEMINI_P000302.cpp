#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    std::string s;
    if (std::cin >> s) {
        std::unordered_set<std::string> dict;
        std::string word;
        while (std::cin >> word) {
            dict.insert(word);
        }
        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        // Update dynamic programming state transition
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    // Update dynamic programming state transition
                    dp[i] = true;
                    break;
                }
            }
        }
        std::cout << (dp[n] ? "Yes" : "No") << std::endl;
    }
    return 0;
}