// Valid Parentheses
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
let st = [];
let pair = {[")"]: "(", ["]"]: "[", ["}"]: "{"};
for (const ch of s) {
    if (_in(ch, "([{")) {
        st.push(ch);
    } else {
        if ((!(st) || st.pop() !== pair[ch])) {
            console.log("false");
            break;
        }
    }
}
