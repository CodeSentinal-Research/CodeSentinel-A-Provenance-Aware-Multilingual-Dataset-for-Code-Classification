// Implement Stack Using Queues
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let q = deque();
let out = [];
for (const _ of Array.from({length: parseInt(_stdin_next_line(), 10)}, (_, i) => i)) {
    let p = _stdin_next_line().trim().split(/\s+/);
    let op = p[0];
    if (op === "push") {
        q.push(p[1]);
        q.rotate(1);
    } else {
        if (op === "pop") {
            out.push((q ? q.popleft() : "-1"));
        } else {
            if (op === "top") {
                out.push((q ? q[0] : "-1"));
            }
        }
    }
}
console.log(out.join("\n"));
