// Josephus Problem Using Recursion
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function josephus(n, k) {
    if (n === 1) {
        return 1;
    }
    return ((((josephus((n - 1), k) + k) - 1) % n) + 1);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let [n, k] = [parseInt(tokens[0], 10), parseInt(tokens[1], 10)];
        console.log(josephus(n, k));
    }
}
main();
