Here is the required C++ code for the given problem:

#include <iostream>
#include <vector>
#include <string>

int longestValidParentheses(std::string s) {
    std::vector<int> dp(s.length(), 0);
    int maxLen = 0;
    for(int i = 1; i < s.length(); i++) {
        if(s[i] == '(') continue;
        else {
            if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                dp[i] = dp[i-1] + 2;
                if(i-dp[i] > 0 && dp[i-dp[i]] > 0) {
                    dp[i] += dp[i-dp[i]];
                }
            } else {
                dp[i] = 0;
            }
        }
        maxLen = std::max(maxLen, dp[i]);
    }
    return maxLen;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << longestValidParentheses(s) << std::endl;
    return 0;
}
This code uses dynamic programming to solve the problem. It uses a vector `dp` to store the length of the longest valid parentheses ending at the current position. The `maxLen` variable is used to store the maximum length found so far. 

The algorithm iterates over the string from the second character to the end, and for each character, it checks if the character is a ')'. If the character is a ')', it checks if the previous character is a '(', and if so, updates the longest valid parentheses ending at the current position as the longest valid parentheses ending at the previous character plus 2 (for the two parentheses themselves). If the previous character is not a '(', it sets the longest valid parentheses ending at the current position to 0.

At the end of each iteration, the maximum length found so far is updated using `std::max`. The result is the maximum length found in the entire string.