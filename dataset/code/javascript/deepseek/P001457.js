function longestCommonSubstring(s1, s2) {
    let dp = new Array(s1.length + 1);
    for(let i = 0; i <= s1.length; i++) {
        dp[i] = new Array(s2.length + 1).fill(0);
    }

    let maxLen = 0;
    for(let i = 1; i <= s1.length; i++) {
        for(let j = 1; j <= s2.length; j++) {
            if(s1[i-1] === s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = Math.max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxLen;
}

let input1 = "abcxyz";
let input2 = "xyzabc";
console.log(longestCommonSubstring(input1, input2));