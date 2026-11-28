// Compute Permutations (nPr)
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function nPr(n, r) {
    if ((r < 0 || r > n)) {
        return 0;
    }
    let ans = 1;
    for (const i of Array.from({length: r}, (_, i) => i)) {
        ans *= (n - i);
    }
    return ans;
}
let [n, r] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(nPr(n, r));
