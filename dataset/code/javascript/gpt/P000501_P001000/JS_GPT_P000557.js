// Race Car
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let target = parseInt(tokens[0], 10);
        let dp = ([0] * (target + 1));
        for (const t of Array.from({length: ((target + 1)) - (1)}, (_, i) => (1) + i)) {
            let k = t.bit_length();
            if (t === ((1 << k) - 1)) {
                dp[t] = k;
                continue;
            }
            dp[t] = ((dp[(((1 << k) - 1) - t)] + k) + 1);
            for (const j of Array.from({length: (k - 1)}, (_, i) => i)) {
                dp[t] = Math.min(dp[t], ((((dp[((t - (1 << (k - 1))) + (1 << j))] + k) - 1) + j) + 2));
            }
        }
        console.log(dp[target]);
    }
}
main();
