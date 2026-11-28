// Largest Rectangle in Histogram
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let h = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let st = [];
let best = 0;
for (const [i, x] of [...(h + [0])].map((v, i) => [i, v])) {
    while ((st && h[st[-(1)]] > x)) {
        let k = st.pop();
        let left = (st ? (st[-(1)] + 1) : 0);
        best = Math.max(best, (h[k] * (i - left)));
    }
    st.push(i);
}
console.log(best);
