// Scramble String
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_scramble(s1, s2) {
    let memo = {};
    function solve(a, b) {
        if (a === b) {
            return true;
        }
        if ([...a].sort((a, b) => a < b ? -1 : a > b ? 1 : 0) !== [...b].sort((a, b) => a < b ? -1 : a > b ? 1 : 0)) {
            return false;
        }
        let key = [a, b];
        if (_in(key, memo)) {
            return memo[key];
        }
        let n = (a.length !== undefined ? a.length : a.size);
        for (const i of Array.from({length: (n) - (1)}, (_, i) => (1) + i)) {
            if (((solve(a.slice(0, i), b.slice(0, i)) && solve(a.slice(i), b.slice(i))) || (solve(a.slice(0, i), b.slice((n - i))) && solve(a.slice(i), b.slice(0, (n - i)))))) {
                memo[key] = true;
                return true;
            }
        }
        memo[key] = false;
        return false;
    }
    return solve(s1, s2);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let [s1, s2] = [tokens[0], tokens[1]];
        console.log((is_scramble(s1, s2) ? "true" : "false"));
    }
}
main();
