// Remove K Digits
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let s = _stdin_next_line();
let k = parseInt(_stdin_next_line(), 10);
let st = [];
for (const ch of s) {
    while ((k && st && st[-(1)] > ch)) {
        st.pop();
        k -= 1;
    }
    st.push(ch);
}
if (k) {
    st = st.slice(0, -(k));
}
let ans = st.join("").trimStart();
console.log((ans || "0"));
