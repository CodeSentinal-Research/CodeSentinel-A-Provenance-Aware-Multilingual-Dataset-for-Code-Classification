Here is the JavaScript code for the problem. This code uses dynamic programming to solve the problem.

function numDecodings(s) {
    const dp = new Array(s.length + 1).fill(0);
    dp[0] = 1;
    dp[1] = s[0] === '0' ? 0 : 1;

    for (let i = 2; i <= s.length; i++) {
        const oneDigit = s[i - 1] === '0' ? 0 : 1;
        const twoDigits = s[i - 2] === '0' ? 0 : (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (oneDigit !== 0) {
            dp[i] += dp[i - 1];
        }
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[s.length];
}

console.log(numDecodings('123'));  // 3
console.log(numDecodings('226'));  // 3
console.log(numDecodings('0'));    // 0
console.log(numDecodings('06'));   // 0

This code defines a function `numDecodings` which takes a string `s` as input and returns the total number of valid decodings. The dynamic programming array `dp` is used to store the number of decodings for each position in `s`. The base cases are set as follows:

- If `s` is empty, there's only one way to decode an empty string, which is to not decode anything (`dp[0] = 1`).
- If `s` only contains one digit, we need to check if it's not 0 and if it's within the valid range (1-26). If both conditions are met, we can decode `s` into one valid digit, so `dp[i] += dp[i - 1]`.

The main part of the function iterates over `s`, and for each position `i`, it checks if the character at position `i` can be a valid digit in `s`. If it can, it checks if the character at position `i - 1` and `i - 2` can be a valid two-digit number in `s`. If both conditions are met, it means `s` can be decoded into one valid digit, so `dp[i] += dp[i - 2]`.

Finally, it returns `dp[s.length]`, which is the total number of valid decodings.