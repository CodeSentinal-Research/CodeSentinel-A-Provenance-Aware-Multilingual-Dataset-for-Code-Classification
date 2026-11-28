// Reorder Linked List
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
        let res = [];
        let [l, r] = [0, (n - 1)];
        while (l <= r) {
            if (l === r) {
                res.push(vals[l]);
            } else {
                res.push(vals[l]);
                res.push(vals[r]);
            }
            l += 1;
            r -= 1;
        }
        console.log(...res);
    }
}
main();
