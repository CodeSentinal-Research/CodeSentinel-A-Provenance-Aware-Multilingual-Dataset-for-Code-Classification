// Generate All Valid Arithmetic Expressions
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function diff_ways(expr) {
    let res = [];
    for (const [i, c] of [...expr].map((v, i) => [i, v])) {
        if (_in(c, "+-*")) {
            let left = diff_ways(expr.slice(0, i));
            let right = diff_ways(expr.slice((i + 1)));
            for (const l of left) {
                for (const r of right) {
                    res.push(`(${l}${c}${r})`);
                }
            }
        }
    }
    if (!(res)) {
        res.push(expr);
    }
    return res;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let expr = tokens[0];
        let res = [...new Set(diff_ways(expr))].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        for (const e of res) {
            console.log(e);
        }
    }
}
main();
