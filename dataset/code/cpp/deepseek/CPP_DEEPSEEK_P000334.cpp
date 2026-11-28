#include <iostream>
#include <vector>

int shortestWay(std::string source, std::string target) {
    int m = source.size();
    int n = target.size();
    
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -1));
    dp[0][0] = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i && j <= n; j++) {
            if (dp[i - 1][j] != -1) {
                dp[i][j] = dp[i - 1][j];
            }
            if (j < i - 1 && source[i - 1] == target[j]) {
                if (dp[i][j] == -1 || dp[i][j] > dp[i - 1][j] + 1) {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
    }
    
    for (int j = 0; j <= n; j++) {
        if (dp[m][j] != -1 && (dp[m][j] == -1 || dp[m][j] > dp[m][j - 1] + 1)) {
            dp[m][j] = dp[m][j - 1] + 1;
        }
    }
    
    return dp[m][n];
}

int main() {
    std::string source, target;
    std::cin >> source >> target;
    std::cout << shortestWay(source, target) << std::endl;
    return 0;
}