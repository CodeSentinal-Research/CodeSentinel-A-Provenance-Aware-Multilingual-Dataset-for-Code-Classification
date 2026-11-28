// Totient Values from 1 to N
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function phi_1_to_n(n) {
    let phi = Array.from(Array.from({length: (n + 1)}, (_, i) => i));
    for (const i of Array.from({length: ((n + 1)) - (2)}, (_, i) => (2) + i)) {
        if (phi[i] === i) {
            for (const j of _py_range(i, (n + 1), i)) {
                phi[j] -= Math.floor(phi[j] / i);
            }
        }
    }
    return phi.slice(1);
}
let n = parseInt(_stdin_next_line(), 10);
let res = phi_1_to_n(n);
console.log(res.map(String).join(" "));
