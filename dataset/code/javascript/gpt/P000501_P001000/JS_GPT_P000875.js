// Minimum Flips to Make a OR b Equal c
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    minFlips(a, b, c) {
        let flips = 0;
        for (const i of Array.from({length: 32}, (_, i) => i)) {
            let bit_a = ((a >> i) & 1);
            let bit_b = ((b >> i) & 1);
            let bit_c = ((c >> i) & 1);
            if (bit_c === 0) {
                flips += (bit_a + bit_b);
            } else {
                if ((bit_a === 0 && bit_b === 0)) {
                    flips += 1;
                }
            }
        }
        return flips;
    }
}
