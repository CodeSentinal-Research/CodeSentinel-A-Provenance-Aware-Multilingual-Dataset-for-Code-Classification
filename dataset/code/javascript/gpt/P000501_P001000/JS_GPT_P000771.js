// Optimal Binary Search Tree Cost
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function optimal_bst(keys, freq) {
    let n = (keys.length !== undefined ? keys.length : keys.size);
    let dp = [...Array.from({length: n}, (_, i) => i)].map(_ => ([0] * n));
    let sum_freq = [...Array.from({length: n}, (_, i) => i)].map(_ => ([0] * n));
    for (const i of Array.from({length: n}, (_, i) => i)) {
        let s = 0;
        for (const j of Array.from({length: (n) - (i)}, (_, i) => (i) + i)) {
            s += freq[j];
            sum_freq[i][j] = s;
        }
    }
    for (const i of Array.from({length: n}, (_, i) => i)) {
        dp[i][i] = freq[i];
    }
    for (const length of Array.from({length: ((n + 1)) - (2)}, (_, i) => (2) + i)) {
        for (const i of Array.from({length: ((n - length) + 1)}, (_, i) => i)) {
            let j = ((i + length) - 1);
            let min_c = parseFloat("inf");
            for (const r of Array.from({length: ((j + 1)) - (i)}, (_, i) => (i) + i)) {
                let c = ((r > i ? dp[i][(r - 1)] : 0) + (r < j ? dp[(r + 1)][j] : 0));
                min_c = Math.min(min_c, c);
            }
            dp[i][j] = (min_c + sum_freq[i][j]);
        }
    }
    return dp[0][(n - 1)];
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let keys = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let freq = Array.from(tokens.slice((1 + n), (1 + (2 * n))).map(Number));
        console.log(optimal_bst(keys, freq));
    }
}
main();
