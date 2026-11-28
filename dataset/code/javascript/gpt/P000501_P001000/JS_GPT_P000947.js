// Can I Win
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
    canIWin(maxChoosableInteger, desiredTotal) {
        if (desiredTotal <= 0) {
            return true;
        }
        let total = Math.floor((maxChoosableInteger * (maxChoosableInteger + 1)) / 2);
        if (total < desiredTotal) {
            return false;
        }
        let memo = {};
        function helper(mask, current_total) {
            if (_in(mask, memo)) {
                return memo[mask];
            }
            for (const i of Array.from({length: ((maxChoosableInteger + 1)) - (1)}, (_, i) => (1) + i)) {
                if (!((mask & (1 << i)))) {
                    if (((current_total + i) >= desiredTotal || !(helper((mask | (1 << i)), (current_total + i))))) {
                        memo[mask] = true;
                        return true;
                    }
                }
            }
            memo[mask] = false;
            return false;
        }
        return helper(0, 0);
    }
}
