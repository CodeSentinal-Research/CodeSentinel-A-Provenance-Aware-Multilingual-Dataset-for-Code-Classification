// Validate Stack Sequences
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let pushed = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let popped = Array.from(tokens.slice((1 + n), (1 + (2 * n))).map(Number));
        let stack = [];
        let j = 0;
        for (const x of pushed) {
            stack.push(x);
            while ((stack && j < n && stack[-(1)] === popped[j])) {
                stack.pop();
                j += 1;
            }
        }
        console.log((j === n ? "true" : "false"));
    }
}
main();
