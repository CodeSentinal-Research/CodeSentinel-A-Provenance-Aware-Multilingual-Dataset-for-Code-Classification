// Longest Valid Parentheses
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let s = _stdin_all.trim();
    let stack = [-(1)];
    let max_len = 0;
    for (const [i, c] of [...s].map((v, i) => [i, v])) {
        if (c === "(") {
            stack.push(i);
        } else {
            stack.pop();
            if (!(stack)) {
                stack.push(i);
            } else {
                max_len = Math.max(max_len, (i - stack[-(1)]));
            }
        }
    }
    console.log(max_len);
}
main();
