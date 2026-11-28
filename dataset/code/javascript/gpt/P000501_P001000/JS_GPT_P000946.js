// Flip Game II
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    canWin(currentState) {
        let memo = {};
        function helper(s) {
            if (_in(s, memo)) {
                return memo[s];
            }
            for (const i of Array.from({length: ((s.length !== undefined ? s.length : s.size) - 1)}, (_, i) => i)) {
                if (s.slice(i, (i + 2)) === "++") {
                    let next_s = ((s.slice(0, i) + "--") + s.slice((i + 2)));
                    if (!(helper(next_s))) {
                        memo[s] = true;
                        return true;
                    }
                }
            }
            memo[s] = false;
            return false;
        }
        return helper(currentState);
    }
}
