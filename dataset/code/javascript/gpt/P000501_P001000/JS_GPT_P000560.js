// Interleave the First Half of Queue
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let q = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let half = Math.floor(n / 2);
        let first = q.slice(0, half);
        let second = q.slice(half);
        let res = [];
        for (const [a, b] of zip(first, second)) {
            res.push(...[a, b]);
        }
        console.log(...res);
    }
}
main();
