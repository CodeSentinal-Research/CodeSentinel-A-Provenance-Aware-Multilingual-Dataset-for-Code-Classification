// Generate All Combinations of K Elements
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function comb(n, k, start, cur) {
    if ((cur.length !== undefined ? cur.length : cur.size) === k) {
        console.log(...cur);
        return;
    }
    for (const i of Array.from({length: ((n + 1)) - (start)}, (_, i) => (start) + i)) {
        comb(n, k, (i + 1), (cur + [i]));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let [n, k] = [parseInt(tokens[0], 10), parseInt(tokens[1], 10)];
        comb(n, k, 1, []);
    }
}
main();
