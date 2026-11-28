// Basic Calculator II
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function calculate(s) {
    let stack = [];
    let num = 0;
    let sign = "+";
    for (const [i, c] of [...s].map((v, i) => [i, v])) {
        if (/^\d+$/.test(c)) {
            num = ((num * 10) + parseInt(c, 10));
        }
        if ((_in(c, "+-*/") || i === ((s.length !== undefined ? s.length : s.size) - 1))) {
            if (sign === "+") {
                stack.push(num);
            } else {
                if (sign === "-") {
                    stack.push(-(num));
                } else {
                    if (sign === "*") {
                        stack.push((stack.pop() * num));
                    } else {
                        if (sign === "/") {
                            stack.push(parseInt((stack.pop() / num), 10));
                        }
                    }
                }
            }
            sign = c;
            num = 0;
        }
    }
    return stack.reduce((a, b) => a + b, 0);
}
function main() {
    let s = _stdin_all.replace(" ", "").trim();
    if (s) {
        console.log(calculate(s));
    }
}
main();
