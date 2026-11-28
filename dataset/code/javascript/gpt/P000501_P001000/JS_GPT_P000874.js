// Decode XORed Permutation
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    decode(encoded) {
        let n = ((encoded.length !== undefined ? encoded.length : encoded.size) + 1);
        let total_xor = 0;
        for (const i of Array.from({length: ((n + 1)) - (1)}, (_, i) => (1) + i)) {
            total_xor ^= i;
        }
        let odd_xor = 0;
        for (const i of _py_range(1, (encoded.length !== undefined ? encoded.length : encoded.size), 2)) {
            odd_xor ^= encoded[i];
        }
        let first = (total_xor ^ odd_xor);
        let perm = [first];
        for (const x of encoded) {
            perm.push((perm[-(1)] ^ x));
        }
        return perm;
    }
}
