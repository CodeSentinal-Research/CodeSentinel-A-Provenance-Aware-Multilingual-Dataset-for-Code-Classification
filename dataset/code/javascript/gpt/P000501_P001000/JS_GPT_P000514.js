// Ternary Expression Parser
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let s = _stdin_all.trim();
    if (s) {
        let stack = [];
        for (const c of [...s].reverse()) {
            if ((stack && stack[-(1)] === "?")) {
                stack.pop();
                let first = stack.pop();
                stack.pop();
                let second = stack.pop();
                stack.push((c === "T" ? first : second));
            } else {
                stack.push(c);
            }
        }
        console.log(stack[0]);
    }
}
main();
