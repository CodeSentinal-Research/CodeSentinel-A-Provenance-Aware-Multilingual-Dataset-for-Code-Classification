// Evaluate Reverse Polish Notation
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let expr = tokens.slice(1, (1 + n));
        let stack = [];
        for (const token of expr) {
            if (_in(token, ["+", "-", "*", "/"])) {
                let b = stack.pop();
                let a = stack.pop();
                if (token === "+") {
                    stack.push((a + b));
                } else {
                    if (token === "-") {
                        stack.push((a - b));
                    } else {
                        if (token === "*") {
                            stack.push((a * b));
                        } else {
                            if (token === "/") {
                                stack.push(parseInt((a / b), 10));
                            }
                        }
                    }
                }
            } else {
                stack.push(parseInt(token, 10));
            }
        }
        console.log(stack[0]);
    }
}
main();
