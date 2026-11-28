// Baseball Game Score
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let n = parseInt(_stdin_next_line(), 10);
let ops = _stdin_next_line().trim().split(/\s+/);
let st = [];
for (const op of ops) {
    if (op === "+") {
        st.push((st[-(1)] + st[-(2)]));
    } else {
        if (op === "D") {
            st.push((2 * st[-(1)]));
        } else {
            if (op === "C") {
                st.pop();
            } else {
                st.push(parseInt(op, 10));
            }
        }
    }
}
console.log(st.reduce((a, b) => a + b, 0));
