// Count Derangements
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_derangements(n) {
    if (n === 0) {
        return 1;
    }
    if (n === 1) {
        return 0;
    }
    let [prev2, prev1] = [1, 0];
    for (const i of Array.from({length: ((n + 1)) - (2)}, (_, i) => (2) + i)) {
        let curr = ((i - 1) * (prev1 + prev2));
        [prev2, prev1] = [prev1, curr];
    }
    return prev1;
}
let n = parseInt(_stdin_next_line(), 10);
console.log(count_derangements(n));
