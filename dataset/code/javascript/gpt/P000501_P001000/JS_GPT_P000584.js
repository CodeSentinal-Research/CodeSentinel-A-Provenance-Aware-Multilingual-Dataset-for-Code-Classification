// Remove Nth Node From End of List
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let size = parseInt(tokens[0], 10);
        let vals = Array.from(tokens.slice(1, (1 + size)).map(Number));
        let n = parseInt(tokens[(1 + size)], 10);
        let idx = (size - n);
        vals.splice(idx, 1)[0];
        console.log(...vals);
    }
}
main();
