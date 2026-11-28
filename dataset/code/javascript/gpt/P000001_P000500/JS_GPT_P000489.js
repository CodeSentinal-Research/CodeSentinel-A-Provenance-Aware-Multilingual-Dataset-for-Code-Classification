// Min Stack
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let st = [];
let out = [];
for (const _ of Array.from({length: parseInt(_stdin_next_line(), 10)}, (_, i) => i)) {
    let p = _stdin_next_line().trim().split(/\s+/);
    let op = p[0];
    if (op === "push") {
        let x = parseInt(p[1], 10);
        st.push([x, (st ? Math.min(x, st[-(1)][1]) : x)]);
    } else {
        if (op === "pop") {
            if (st) {
                st.pop();
            }
        } else {
            if (op === "top") {
                out.push((st ? String(st[-(1)][0]) : "-1"));
            } else {
                if (_in(op, ["getMin", "min"])) {
                    out.push((st ? String(st[-(1)][1]) : "-1"));
                }
            }
        }
    }
}
console.log(out.join("\n"));
