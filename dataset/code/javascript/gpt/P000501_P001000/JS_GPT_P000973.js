// Probability of Dice Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function dice_sum_prob(n, target) {
    if ((target < n || target > (6 * n))) {
        return 0.0;
    }
    let dp = ([0.0] * ((6 * n) + 1));
    for (const i of Array.from({length: (7) - (1)}, (_, i) => (1) + i)) {
        dp[i] = (1.0 / 6.0);
    }
    for (const dice of Array.from({length: ((n + 1)) - (2)}, (_, i) => (2) + i)) {
        let next_dp = ([0.0] * ((6 * n) + 1));
        for (const s of Array.from({length: (((6 * dice) + 1)) - (dice)}, (_, i) => (dice) + i)) {
            for (const face of Array.from({length: (7) - (1)}, (_, i) => (1) + i)) {
                if ((s - face) >= (dice - 1)) {
                    next_dp[s] += (dp[(s - face)] / 6.0);
                }
            }
        }
        dp = next_dp;
    }
    return dp[target];
}
let [n, target] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(`${dice_sum_prob(n, target)}`);
