// Wildcard Pattern Matching
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_match(s, p) {
    let memo = {};
    function backtrack(i, j) {
        if (_in([i, j], memo)) {
            return memo[[i, j]];
        }
        if (j === (p.length !== undefined ? p.length : p.size)) {
            return i === (s.length !== undefined ? s.length : s.size);
        }
        if (i === (s.length !== undefined ? s.length : s.size)) {
            return [...p.slice(j)].map(c => c === "*").every(Boolean);
        }
        if (_in(p[j], [s[i], "?"])) {
            let res = backtrack((i + 1), (j + 1));
        } else {
            if (p[j] === "*") {
                res = (backtrack((i + 1), j) || backtrack(i, (j + 1)));
            } else {
                res = false;
            }
        }
        memo[[i, j]] = res;
        return res;
    }
    return backtrack(0, 0);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let s = tokens[0];
        let p = ((tokens.length !== undefined ? tokens.length : tokens.size) > 1 ? tokens[1] : "");
        console.log((is_match(s, p) ? "true" : "false"));
    }
}
main();
