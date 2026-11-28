// Remove Duplicates from Sorted Array
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let n = parseInt(_stdin_next_line(), 10);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number)).slice(0, n);
if (n) {
    let write = 1;
    for (const read of Array.from({length: (n) - (1)}, (_, i) => (1) + i)) {
        if (a[read] !== a[(write - 1)]) {
            a[write] = a[read];
            write += 1;
        }
    }
    console.log(write);
} else {
    console.log(0);
}
