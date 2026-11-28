// Remove Nodes From Linked List
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
        let stack = [];
        for (const v of vals) {
            while ((stack && stack[-(1)] < v)) {
                stack.pop();
            }
            stack.push(v);
        }
        console.log(...stack);
    }
}
main();
