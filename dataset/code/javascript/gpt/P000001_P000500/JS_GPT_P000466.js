// Find Triplet with Given Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [n, t] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let ok = false;
for (const i of Array.from({length: (n - 2)}, (_, i) => i)) {
    let [l, r] = [(i + 1), (n - 1)];
    while (l < r) {
        let s = ((a[i] + a[l]) + a[r]);
        if (s === t) {
            ok = true;
            break;
        }
        if (s < t) {
            l += 1;
        } else {
            r -= 1;
        }
    }
    if (ok) {
        break;
    }
}
console.log((ok ? "Yes" : "No"));
