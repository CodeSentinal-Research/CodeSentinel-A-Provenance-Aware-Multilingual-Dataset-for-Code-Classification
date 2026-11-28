// Different Ways to Add Parentheses
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function diff_ways_to_compute(expr) {
    let res = [];
    for (const [i, c] of [...expr].map((v, i) => [i, v])) {
        if (_in(c, "+-*")) {
            let left = diff_ways_to_compute(expr.slice(0, i));
            let right = diff_ways_to_compute(expr.slice((i + 1)));
            for (const l of left) {
                for (const r of right) {
                    if (c === "+") {
                        res.push((l + r));
                    } else {
                        if (c === "-") {
                            res.push((l - r));
                        } else {
                            if (c === "*") {
                                res.push((l * r));
                            }
                        }
                    }
                }
            }
        }
    }
    if (!(res)) {
        res.push(parseInt(expr, 10));
    }
    return res;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let res = [...diff_ways_to_compute(tokens[0])].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        console.log(...res);
    }
}
main();
