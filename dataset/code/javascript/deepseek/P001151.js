function longestPalindromicSubstring(s) {
    let len = s.length;
    let dp = Array(len).fill(null).map(() => Array(len).fill(false));
    let longest = 1;
    for (let i = 0; i < len; i++) {
        dp[i][i] = true;
    }

    let start = 0;
    for (let i = 0; i < len - 1; i++) {
        if (s[i] === s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            longest = 2;
        }
    }

    for (let length = 3; length <= len; length++) {
        for (let i = 0; i < len - length + 1; i++) {
            let j = i + length - 1;
            if (s[i] === s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                longest = length;
            }
        }
    }

    return s.substring(start, start + longest);
}

console.log(longestPalindromicSubstring("babad")); // Output: bab
console.log(longestPalindromicSubstring("cbbd")); // Output: bb