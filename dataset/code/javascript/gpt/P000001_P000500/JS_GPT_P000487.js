// Trapping Rain Water
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let h = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let l = 0;
let r = ((h.length !== undefined ? h.length : h.size) - 1);
let lm = 0;
let rm = 0;
let ans = 0;
while (l <= r) {
    if (h[l] <= h[r]) {
        lm = Math.max(lm, h[l]);
        ans += (lm - h[l]);
        l += 1;
    } else {
        rm = Math.max(rm, h[r]);
        ans += (rm - h[r]);
        r -= 1;
    }
}
console.log(ans);
