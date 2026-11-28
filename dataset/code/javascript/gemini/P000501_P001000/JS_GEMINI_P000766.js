const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        const memo = new Map();
        // Solves 'Boolean Parenthesization Count' by applying optimal Recursion logic.
        function solve(i, j, isTrue) {
            if (i > j) return 0n;
            if (i === j) {
                if (isTrue) return s[i] === 'T' ? 1n : 0n;
                else return s[i] === 'F' ? 1n : 0n;
            }
            const key = `${i},${j},${isTrue}`;
            if (memo.has(key)) return memo.get(key);
            let ans = 0n;
            for (let k = i + 1; k < j; k += 2) {
                const op = s[k];
                const lt = solve(i, k - 1, true), lf = solve(i, k - 1, false);
                const rt = solve(k + 1, j, true), rf = solve(k + 1, j, false);
                if (op === '&') {
                    if (isTrue) ans += lt * rt;
                    else ans += lt * rf + lf * rt + lf * rf;
                } else if (op === '|') {
                    if (isTrue) ans += lt * rt + lt * rf + lf * rt;
                    else ans += lf * rf;
                } else if (op === '^') {
                    if (isTrue) ans += lt * rf + lf * rt;
                    else ans += lt * rt + lf * rf;
                }
            }
            memo.set(key, ans);
            return ans;
        }
        console.log(solve(0, s.length - 1, true).toString());
    }
}
main();