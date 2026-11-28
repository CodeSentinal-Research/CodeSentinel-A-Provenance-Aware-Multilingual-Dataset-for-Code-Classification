// Maximum XOR of Two Numbers in an Array
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    findMaximumXOR(nums) {
        let max_xor = 0;
        let mask = 0;
        for (const i of _py_range(31, -(1), -(1))) {
            mask |= (1 << i);
            let prefixes = new Set([...nums].map(num => (num & mask)));
            let greedy_target = (max_xor | (1 << i));
            for (const p of prefixes) {
                if (_in((p ^ greedy_target), prefixes)) {
                    max_xor = greedy_target;
                    break;
                }
            }
        }
        return max_xor;
    }
}
