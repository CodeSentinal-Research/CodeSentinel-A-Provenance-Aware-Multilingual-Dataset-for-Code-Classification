// Find Right Interval
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    findRightInterval(intervals) {
        let starts = [...[...[...intervals].map((v, i) => [i, v])].map(([i, iv]) => [iv[0], i])].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        let start_vals = [...starts].map(s => s[0]);
        let res = [];
        for (const iv of intervals) {
            let idx = bisect.bisect_left(start_vals, iv[1]);
            if (idx < (start_vals.length !== undefined ? start_vals.length : start_vals.size)) {
                res.push(starts[idx][1]);
            } else {
                res.push(-(1));
            }
        }
        return res;
    }
}
