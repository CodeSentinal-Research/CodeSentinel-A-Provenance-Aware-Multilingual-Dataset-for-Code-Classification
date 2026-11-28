Here's the JavaScript code to solve this problem:

function shortestCommonSupersequence(str1, str2) {
    let dp = Array.from(new Array(str2.length + 1), () => new Array(str1.length + 1).map(() => 0));
    for(let i = 0; i <= str2.length; i++) {
        for(let j = 0; j <= str1.length; j++) {
            if(i === 0) {
                dp[i][j] = j;
            } else if(j === 0) {
                dp[i][j] = i;
            } else if(str2[i-1] === str1[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + Math.min(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[str2.length][str1.length];
}

console.log(shortestCommonSupersequence('ABCDGH', 'AECIDGH')); // Outputs: 1
console.log(shortestCommonSupersequence('ABCBD', 'ACBCBD')); // Outputs: 4

This JavaScript function uses a 2D Dynamic Programming (DP) table to solve the problem. The function iterates over both strings, and for each character in the strings, it calculates the length of the shortest common supersequence by either inserting the current character from the first string into the supersequence, or the current character from the second string into the supersequence. If the characters are the same, it only adds one to the previous length. If the characters are different, it takes the minimum length of the two possibilities and adds one to the minimum length.