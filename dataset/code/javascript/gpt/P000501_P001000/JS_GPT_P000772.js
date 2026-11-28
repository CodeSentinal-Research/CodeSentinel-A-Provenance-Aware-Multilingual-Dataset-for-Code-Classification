// Recursive Egg Dropping Problem
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function egg_drop(e, f) {
    let dp = [...Array.from({length: (e + 1)}, (_, i) => i)].map(_ => ([0] * (f + 1)));
    for (const i of Array.from({length: ((e + 1)) - (1)}, (_, i) => (1) + i)) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for (const j of Array.from({length: ((f + 1)) - (1)}, (_, i) => (1) + i)) {
        dp[1][j] = j;
    }
    for (const i of Array.from({length: ((e + 1)) - (2)}, (_, i) => (2) + i)) {
        for (const j of Array.from({length: ((f + 1)) - (2)}, (_, i) => (2) + i)) {
            dp[i][j] = parseFloat("inf");
            for (const x of Array.from({length: ((j + 1)) - (1)}, (_, i) => (1) + i)) {
                let res = (1 + Math.max(dp[(i - 1)][(x - 1)], dp[i][(j - x)]));
                dp[i][j] = Math.min(dp[i][j], res);
            }
        }
    }
    return dp[e][f];
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let [e, f] = [parseInt(tokens[0], 10), parseInt(tokens[1], 10)];
        console.log(egg_drop(e, f));
    }
}
main();
