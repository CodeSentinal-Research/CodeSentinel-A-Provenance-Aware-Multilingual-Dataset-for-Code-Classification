// Asteroid Collision
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let st = [];
for (const x of _stdin_next_line().trim().split(/\s+/).map(Number)) {
    let alive = true;
    while ((alive && x < 0 && st && st[-(1)] > 0)) {
        if (st[-(1)] < -(x)) {
            st.pop();
            continue;
        }
        if (st[-(1)] === -(x)) {
            st.pop();
        }
        alive = false;
    }
    if (alive) {
        st.push(x);
    }
}
console.log(...st);
