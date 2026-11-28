// Delete Duplicates from Sorted Linked List II
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
        let counts = Counter(vals);
        let res = [...vals].filter(x => counts[x] === 1).map(x => x);
        console.log(...res);
    }
}
main();
