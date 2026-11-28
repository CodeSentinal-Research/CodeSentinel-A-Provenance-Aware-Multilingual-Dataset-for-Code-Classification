// Count Ways to Parenthesize Arithmetic Expression
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_max_parenthesize(expr) {
    let memo = {};
    function solve(i, j) {
        if (i === j) {
            let val = parseInt(expr[i], 10);
            return {[val]: 1};
        }
        if (_in([i, j], memo)) {
            return memo[[i, j]];
        }
        let res = {};
        for (const k of _py_range((i + 1), j, 2)) {
            let op = expr[k];
            let left = solve(i, (k - 1));
            let right = solve((k + 1), j);
            for (const [lv, lcnt] of Object.entries(left)) {
                for (const [rv, rcnt] of Object.entries(right)) {
                    if (op === "+") {
                        let v = (lv + rv);
                    } else {
                        if (op === "-") {
                            v = (lv - rv);
                        } else {
                            if (op === "*") {
                                v = (lv * rv);
                            }
                        }
                    }
                    res[v] = ((res[v] !== undefined ? res[v] : 0) + (lcnt * rcnt));
                }
            }
        }
        memo[[i, j]] = res;
        return res;
    }
    let all_res = solve(0, ((expr.length !== undefined ? expr.length : expr.size) - 1));
    let max_v = Math.max(...Object.keys(all_res));
    return all_res[max_v];
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        console.log(count_max_parenthesize(tokens[0]));
    }
}
main();
