// Reverse Substrings Between Parentheses
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let s = _stdin_all.trim();
    if (s) {
        let stack = [];
        for (const c of s) {
            if (c === ")") {
                let temp = [];
                while ((stack && stack[-(1)] !== "(")) {
                    temp.push(stack.pop());
                }
                stack.pop();
                stack.push(...temp);
            } else {
                stack.push(c);
            }
        }
        console.log(stack.join(""));
    }
}
main();
