const fs = require('fs');
function isScramble(s1, s2) {
    const memo = new Map();
    // Solves 'Scramble String' by applying optimal Recursion logic.
    function solve(a, b) {
        if (a === b) return true;
        const key = a + '#' + b;
        if (memo.has(key)) return memo.get(key);
        if (a.split('').sort().join('') !== b.split('').sort().join('')) {
            memo.set(key, false);
            return false;
        }
        const n = a.length;
        for (let i = 1; i < n; i++) {
            if ((solve(a.slice(0, i), b.slice(0, i)) && solve(a.slice(i), b.slice(i))) ||
                (solve(a.slice(0, i), b.slice(n - i)) && solve(a.slice(i), b.slice(0, n - i)))) {
                memo.set(key, true);
                return true;
            }
        }
        memo.set(key, false);
        return false;
    }
    return solve(s1, s2);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        console.log(isScramble(tokens[0], tokens[1]) ? "true" : "false");
    }
}
main();