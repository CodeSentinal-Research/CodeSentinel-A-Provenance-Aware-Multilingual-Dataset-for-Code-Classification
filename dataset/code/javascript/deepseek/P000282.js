Here's a simple implementation of the Longest Common Substring problem using dynamic programming in JavaScript:

function longestCommonSubstring(S1, S2) {
    let len1 = S1.length;
    let len2 = S2.length;
    let maxLen = 0;
    let endMax = 0;
    let dpTable = new Array(len1 + 1);
    for(let i = 0; i <= len1; i++) {
        dpTable[i] = new Array(len2 + 1).fill(0);
    }

    for(let i = 1; i <= len1; i++) {
        for(let j = 1; j <= len2; j++) {
            if(S1[i-1] === S2[j-1]) {
                dpTable[i][j] = dpTable[i-1][j-1] + 1;
                if(dpTable[i][j] > maxLen) {
                    maxLen = dpTable[i][j];
                    endMax = i;
                }
            } else {
                dpTable[i][j] = 0;
            }
        }
    }

    if(maxLen === 0) return "";

    return S1.substring(endMax - maxLen, endMax);
}

console.log(longestCommonSubstring("abcde", "ace")); // Outputs: "ace"

This code creates a 2D DP table and initializes it to 0. Then it iterates over each character in both strings, updating the DP table based on the current character in both strings. If the characters match, it increments the count in the DP table for the current character pair, and updates the maximum length and end index if necessary. If the characters do not match, it resets the count in the DP table. After the iteration, it returns the longest common substring from the end index to the maximum length.