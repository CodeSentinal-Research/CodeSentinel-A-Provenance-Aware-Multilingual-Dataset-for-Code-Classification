// Convert Between Arbitrary Bases
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function convert_base(num_str, from_base, to_base) {
    let val = parseInt(num_str, from_base);
    if (val === 0) {
        return "0";
    }
    let digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let res = [];
    while (val > 0) {
        res.push(digits[(val % to_base)]);
        val = Math.floor(val / (to_base));
    }
    return [...res].reverse().join("");
}
let [s, b1, b2] = _stdin_next_line().trim().split(/\s+/);
console.log(convert_base(s, parseInt(b1, 10), parseInt(b2, 10)));
