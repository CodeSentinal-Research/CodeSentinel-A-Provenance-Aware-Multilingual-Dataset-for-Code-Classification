// Linear Recurrence Evaluation
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let MOD = (Math.pow(10, 9) + 7);
function eval_linear_recurrence(coeffs, init, n) {
    let k = (coeffs.length !== undefined ? coeffs.length : coeffs.size);
    if (n < k) {
        return (init[n] % MOD);
    }
    let dp = Array.from(init);
    for (const i of Array.from({length: ((n + 1)) - (k)}, (_, i) => (k) + i)) {
        let val = ([...Array.from({length: k}, (_, i) => i)].map(j => (coeffs[j] * dp[((i - 1) - j)])).reduce((a, b) => a + b, 0) % MOD);
        dp.push(val);
    }
    return dp[n];
}
let [k, n] = _stdin_next_line().trim().split(/\s+/).map(Number);
let coeffs = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let init = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
console.log(eval_linear_recurrence(coeffs, init, n));
