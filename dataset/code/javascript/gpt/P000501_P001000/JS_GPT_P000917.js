// Distribute Identical Balls into Distinct Boxes
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function stars_and_bars(n, k) {
    let total = ((n + k) - 1);
    let r = (k - 1);
    if ((r < 0 || r > total)) {
        return 0;
    }
    r = Math.min(r, (total - r));
    let ans = 1;
    for (const i of Array.from({length: ((r + 1)) - (1)}, (_, i) => (1) + i)) {
        ans = Math.floor((ans * ((total - i) + 1)) / i);
    }
    return ans;
}
let [n, k] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(stars_and_bars(n, k));
