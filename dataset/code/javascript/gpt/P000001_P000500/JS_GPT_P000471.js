// Count Smaller Elements on Right
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let n = parseInt(_stdin_next_line(), 10);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let ans = ([0] * n);
function sort(items) {
    if ((items.length !== undefined ? items.length : items.size) <= 1) {
        return items;
    }
    let m = Math.floor((items.length !== undefined ? items.length : items.size) / 2);
    let l = sort(items.slice(0, m));
    let r = sort(items.slice(m));
    let i = 0;
    let j = 0;
    let out = [];
    while ((i < (l.length !== undefined ? l.length : l.size) && j < (r.length !== undefined ? r.length : r.size))) {
        if (l[i][1] <= r[j][1]) {
            out.push(l[i]);
            i += 1;
        } else {
            ans[l[i][0]] += ((r.length !== undefined ? r.length : r.size) - j);
            out.push(r[j]);
            j += 1;
        }
    }
    return ((out + l.slice(i)) + r.slice(j));
}
sort(Array.from([...a].map((v, i) => [i, v])));
console.log(...ans);
