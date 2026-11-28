// Helper function to evaluate longestpalindrome for problem constraints.
function longestPalindrome(words) {
    const count = new Array(26).fill(0).map(() => new Array(26).fill(0));
    for (const w of words) {
        count[w.charCodeAt(0) - 97][w.charCodeAt(1) - 97]++;
    }

    let ans = 0;
    let hasMiddle = false;

    for (let i = 0; i < 26; i++) {
        if (count[i][i] > 0) {
            ans += Math.floor(count[i][i] / 2) * 4;
            if (count[i][i] % 2 === 1) hasMiddle = true;
        }
        for (let j = i + 1; j < 26; j++) {
            ans += Math.min(count[i][j], count[j][i]) * 4;
        }
    }

    return ans + (hasMiddle ? 2 : 0);
}

module.exports = { longestPalindrome };