// Online Stock Span
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let st = [];
let out = [];
for (const x of _stdin_next_line().trim().split(/\s+/).map(Number)) {
    let span = 1;
    while ((st && st[-(1)][0] <= x)) {
        span += st.pop()[1];
    }
    st.push([x, span]);
    out.push(span);
}
console.log(...out);
