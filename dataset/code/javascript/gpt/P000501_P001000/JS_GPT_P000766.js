// Boolean Parenthesization Count
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_paren(s) {
    let memo = {};
    function solve(i, j, is_true) {
        if (i > j) {
            return 0;
        }
        if (i === j) {
            if (is_true) {
                return (s[i] === "T" ? 1 : 0);
            } else {
                return (s[i] === "F" ? 1 : 0);
            }
        }
        let key = [i, j, is_true];
        if (_in(key, memo)) {
            return memo[key];
        }
        let ans = 0;
        for (const k of _py_range((i + 1), j, 2)) {
            let op = s[k];
            let lt = solve(i, (k - 1), true);
            let lf = solve(i, (k - 1), false);
            let rt = solve((k + 1), j, true);
            let rf = solve((k + 1), j, false);
            if (op === "&") {
                if (is_true) {
                    ans += (lt * rt);
                } else {
                    ans += (((lt * rf) + (lf * rt)) + (lf * rf));
                }
            } else {
                if (op === "|") {
                    if (is_true) {
                        ans += (((lt * rt) + (lt * rf)) + (lf * rt));
                    } else {
                        ans += (lf * rf);
                    }
                } else {
                    if (op === "^") {
                        if (is_true) {
                            ans += ((lt * rf) + (lf * rt));
                        } else {
                            ans += ((lt * rt) + (lf * rf));
                        }
                    }
                }
            }
        }
        memo[key] = ans;
        return ans;
    }
    return solve(0, ((s.length !== undefined ? s.length : s.size) - 1), true);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        console.log(count_paren(tokens[0]));
    }
}
main();
