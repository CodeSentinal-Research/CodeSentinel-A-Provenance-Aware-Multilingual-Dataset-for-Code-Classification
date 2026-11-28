// Count Unique Binary Search Trees
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function num_trees(n) {
    let c = 1;
    for (const i of Array.from({length: n}, (_, i) => i)) {
        c = Math.floor(((c * 2) * ((2 * i) + 1)) / (i + 2));
    }
    return c;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        console.log(num_trees(n));
    }
}
main();
