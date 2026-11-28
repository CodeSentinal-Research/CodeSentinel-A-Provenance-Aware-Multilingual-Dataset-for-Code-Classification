Here is the JavaScript code to solve the problem:

function countDistinctPalindromicSubstrings(s) {
    let set = new Set();
    let dp = new Array(s.length + 1).fill(0).map(() => []);

    for (let i = 0; i < s.length; i++) {
        dp[i + 1].push(s[i]);
        set.add(s[i]);
        for (let j = 0; j < i; j++) {
            if (s[i] === s[j] && (dp[i + 1][j] || dp[i + 1][j + 1])) {
                dp[i + 1].push(s[i] + dp[i + 1][j] + s[j]);
                set.add(dp[i + 1][j] + dp[i + 1][j + 1]);
            }
        }
    }

    console.log(set.size);
}

countDistinctPalindromicSubstrings("abc");

This code creates a 2D array `dp` where each cell `dp[i][j]` is a string constructed from `s` starting from `i` and ending at `j`. Then it uses a `Set` to store all the distinct palindromic substrings.

In the main function, it iterates over all the characters in the string `s` and for each character, it checks if it's the same as the previous character. If it is, then it appends the current character to the front and end of the string stored in `dp[i + 1][j]` and `dp[i + 1][j + 1]`.

Finally, it logs the size of the `Set`, which contains all the distinct palindromic substrings, to the console.