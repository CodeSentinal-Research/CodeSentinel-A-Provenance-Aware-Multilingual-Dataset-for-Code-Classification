// Count Distinct Subsequences
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function num_distinct(s, t) {
    let memo = {};
    function backtrack(i, j) {
        if (j === (t.length !== undefined ? t.length : t.size)) {
            return 1;
        }
        if (i === (s.length !== undefined ? s.length : s.size)) {
            return 0;
        }
        if (_in([i, j], memo)) {
            return memo[[i, j]];
        }
        let res = backtrack((i + 1), j);
        if (s[i] === t[j]) {
            res += backtrack((i + 1), (j + 1));
        }
        memo[[i, j]] = res;
        return res;
    }
    return backtrack(0, 0);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let [s, t] = [tokens[0], tokens[1]];
        console.log(num_distinct(s, t));
    }
}
main();
