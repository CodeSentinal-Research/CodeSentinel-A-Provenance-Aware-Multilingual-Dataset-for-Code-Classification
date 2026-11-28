// Search in Bitonic Array
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
let [l, r] = [0, (n - 1)];
while (l < r) {
    let m = Math.floor((l + r) / 2);
    if (a[m] < a[(m + 1)]) {
        l = (m + 1);
    } else {
        r = m;
    }
}
let p = l;
function bs(l, r, inc) {
    while (l <= r) {
        m = Math.floor((l + r) / 2);
        if (a[m] === t) {
            return m;
        }
        if (inc) {
            if (a[m] < t) {
                l = (m + 1);
            } else {
                r = (m - 1);
            }
        } else {
            if (a[m] > t) {
                l = (m + 1);
            } else {
                r = (m - 1);
            }
        }
    }
    return -(1);
}
let x = bs(0, p, true);
console.log((x !== -(1) ? x : bs((p + 1), (n - 1), false)));
