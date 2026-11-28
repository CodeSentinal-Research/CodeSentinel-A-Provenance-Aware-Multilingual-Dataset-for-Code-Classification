// Score of Parentheses
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let s = _stdin_all.trim();
    if (s) {
        let stack = [0];
        for (const c of s) {
            if (c === "(") {
                stack.push(0);
            } else {
                let v = stack.pop();
                stack[-(1)] += Math.max((2 * v), 1);
            }
        }
        console.log(stack[0]);
    }
}
main();
