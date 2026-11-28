// Recursive Matrix Chain Multiplication
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function mcm(dims) {
    let memo = {};
    function solve(i, j) {
        if (i >= j) {
            return 0;
        }
        if (_in([i, j], memo)) {
            return memo[[i, j]];
        }
        let min_cost = parseFloat("inf");
        for (const k of Array.from({length: (j) - (i)}, (_, i) => (i) + i)) {
            let cost = ((solve(i, k) + solve((k + 1), j)) + ((dims[(i - 1)] * dims[k]) * dims[j]));
            min_cost = Math.min(min_cost, cost);
        }
        memo[[i, j]] = min_cost;
        return min_cost;
    }
    return solve(1, ((dims.length !== undefined ? dims.length : dims.size) - 1));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let dims = Array.from(tokens.slice(1, (1 + n)).map(Number));
        console.log(mcm(dims));
    }
}
main();
