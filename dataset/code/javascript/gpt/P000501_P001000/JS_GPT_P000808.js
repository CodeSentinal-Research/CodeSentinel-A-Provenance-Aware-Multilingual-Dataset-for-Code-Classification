// Maximum Length Subarray with Equal Even and Odd Numbers
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function max_len_equal_even_odd(arr) {
    let prefix_map = {[0]: -(1)};
    let prefix = 0;
    let max_len = 0;
    for (const [i, x] of [...arr].map((v, i) => [i, v])) {
        prefix += ((x % 2) === 0 ? 1 : -(1));
        if (_in(prefix, prefix_map)) {
            max_len = Math.max(max_len, (i - prefix_map[prefix]));
        } else {
            prefix_map[prefix] = i;
        }
    }
    return max_len;
}
let n = parseInt(_stdin_next_line(), 10);
let arr = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
console.log(max_len_equal_even_odd(arr));
