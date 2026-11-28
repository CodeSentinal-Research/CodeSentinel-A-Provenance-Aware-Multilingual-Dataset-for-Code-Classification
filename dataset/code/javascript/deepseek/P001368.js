Here is the JavaScript code to solve the problem:

function countVowelStrings(n) {
    if (n < 1 || n > 50) {
        throw new Error('Invalid input. Please enter a number between 1 and 50.');
    }

    let dp = new Array(n + 1).fill(0);
    let MOD = 1e9 + 7;

    dp[0] = 1;
    for (let i = 1; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + '0'.repeat(i)) % MOD;
    }

    return dp[n];
}

console.log(countVowelStrings(3));

This code uses dynamic programming to solve the problem. The dynamic programming array dp is initialized to 0 and size is set to n+1. dp[i] represents the number of strings of length i. The base cases are dp[0] = 1, meaning there's only one string of length 0 (empty string).

For each length from 1 to n (inclusive), the number of strings is the sum of the number of strings of the previous length (dp[i - 1]) plus the number of strings of the previous length - 1 (dp[i - 2]) plus the number of strings of length i (considered as a string with a single character). This is because if we append a vowel at the end of a string of length i, there are already two strings of length i (the string itself and the new vowel), and there are no more strings of length i-1 (all the previous vowels).

The modulo operation is applied to prevent the number of strings from getting too large. Finally, the function returns the number of strings of length n.