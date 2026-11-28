// Merge Two Sorted Linked Lists
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let l1 = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let m = parseInt(tokens[(1 + n)], 10);
        let l2 = Array.from(tokens.slice((2 + n), ((2 + n) + m)).map(Number));
        let res = [...(l1 + l2)].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        console.log(...res);
    }
}
main();
