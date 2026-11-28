// Stone Game II
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    stoneGameII(piles) {
        let n = (piles.length !== undefined ? piles.length : piles.size);
        let suffix = ([0] * (n + 1));
        for (const i of _py_range((n - 1), -(1), -(1))) {
            suffix[i] = (suffix[(i + 1)] + piles[i]);
        }
        function dp(i, m) {
            if (i >= n) {
                return 0;
            }
            if ((i + (2 * m)) >= n) {
                return suffix[i];
            }
            let res = 0;
            for (const x of Array.from({length: (((2 * m) + 1)) - (1)}, (_, i) => (1) + i)) {
                res = Math.max(res, (suffix[i] - dp((i + x), Math.max(m, x))));
            }
            return res;
        }
        return dp(0, 1);
    }
}
