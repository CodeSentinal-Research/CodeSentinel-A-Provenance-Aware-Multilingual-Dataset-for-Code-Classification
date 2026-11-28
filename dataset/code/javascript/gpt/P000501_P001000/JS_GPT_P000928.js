// Binary Addition
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    addBinary(a, b) {
        let [i, j] = [((a.length !== undefined ? a.length : a.size) - 1), ((b.length !== undefined ? b.length : b.size) - 1)];
        let carry = 0;
        let res = [];
        while ((i >= 0 || j >= 0 || carry)) {
            let total = carry;
            if (i >= 0) {
                total += parseInt(a[i], 10);
                i -= 1;
            }
            if (j >= 0) {
                total += parseInt(b[j], 10);
                j -= 1;
            }
            res.push(String((total % 2)));
            carry = Math.floor(total / 2);
        }
        return [...res].reverse().join("");
    }
}
