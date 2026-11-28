// Reverse Linked List II
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let vals = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let left = (parseInt(tokens[(1 + n)], 10) - 1);
        let right = (parseInt(tokens[(2 + n)], 10) - 1);
        vals.slice(left, (right + 1)) = vals.slice(left, (right + 1)).slice(0);
        console.log(...vals);
    }
}
main();
