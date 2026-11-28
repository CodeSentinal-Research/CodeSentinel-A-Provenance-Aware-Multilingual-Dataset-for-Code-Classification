// Reverse Nodes in K-Group
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let vals = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let k = parseInt(tokens[(1 + n)], 10);
        let res = [];
        for (const i of _py_range(0, n, k)) {
            let chunk = vals.slice(i, (i + k));
            if ((chunk.length !== undefined ? chunk.length : chunk.size) === k) {
                res.push(...chunk.slice(0));
            } else {
                res.push(...chunk);
            }
        }
        console.log(...res);
    }
}
main();
