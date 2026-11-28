// Reverse First K Elements of Queue
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
        let k = parseInt(tokens[(1 + n)], 10);
        q = (q.slice(0, k).slice(0) + q.slice(k));
        console.log(...q);
    }
}
main();
