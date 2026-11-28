// K-th Symbol in Grammar
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function kth_grammar(n, k) {
    if (n === 1) {
        return 0;
    }
    let parent = kth_grammar((n - 1), Math.floor((k + 1) / 2));
    if (parent === 0) {
        return ((k % 2) !== 0 ? 0 : 1);
    } else {
        return ((k % 2) !== 0 ? 1 : 0);
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let [n, k] = [parseInt(tokens[0], 10), parseInt(tokens[1], 10)];
        console.log(kth_grammar(n, k));
    }
}
main();
