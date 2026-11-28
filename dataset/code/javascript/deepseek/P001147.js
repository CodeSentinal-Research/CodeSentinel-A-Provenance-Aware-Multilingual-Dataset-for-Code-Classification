Here is the JavaScript code to solve the problem:

function longestCommonSubstring(str1, str2) {
    let len1 = str1.length;
    let len2 = str2.length;

    let dp = new Array(len1 + 1);
    for(let i = 0; i <= len1; i++) {
        dp[i] = new Array(len2 + 1).fill(0);
    }

    let maxLen = 0;
    let endIndex = -1;

    for(let i = 1; i <= len1; i++) {
        for(let j = 1; j <= len2; j++) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return endIndex - maxLen + 1;
}

This function uses a dynamic programming approach to find the longest common substring in two strings. It creates a 2D array `dp` where `dp[i][j]` represents the length of the longest common substring of `str1` and `str2` up to `str1[i]` and `str2[j]`. The dynamic programming process involves iterating through `str1` and `str2`, comparing each character from both strings. If they are the same, then the length of the common substring is `dp[i - 1][j - 1] + 1`, otherwise it is `0`. The longest common substring is found by iterating from `str1` and `str2` and updating `maxLen` and `endIndex` as necessary. Finally, the longest common substring is returned by subtracting `maxLen` from `endIndex` and adding `1` to get the actual length.