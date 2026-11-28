// Basic Calculator
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let s = _stdin_next_line();
let stack = [];
let num = 0;
let sign = 1;
let total = 0;
let i = 0;
while (i < (s.length !== undefined ? s.length : s.size)) {
    let ch = s[i];
    if (/^\d+$/.test(ch)) {
        num = ((num * 10) + parseInt(ch, 10));
    } else {
        if (_in(ch, "+-")) {
            total += (sign * num);
            num = 0;
            sign = (ch === "+" ? 1 : -(1));
        } else {
            if (ch === "(") {
                stack.push([total, sign]);
                total = 0;
                sign = 1;
            } else {
                if (ch === ")") {
                    total += (sign * num);
                    num = 0;
                    let [prev, op] = stack.pop();
                    total = (prev + (op * total));
                }
            }
        }
    }
    i += 1;
}
console.log((total + (sign * num)));
