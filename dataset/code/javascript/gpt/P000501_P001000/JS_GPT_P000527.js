// Parse Boolean Expression
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function parseBoolExpr(expression) {
    let stack = [];
    for (const c of expression) {
        if (_in(c, ",(")) {
            continue;
        } else {
            if (_in(c, "tf!&|")) {
                stack.push(c);
            } else {
                if (c === ")") {
                    let seen_t = false;
                    let seen_f = false;
                    while ((stack && _in(stack[-(1)], "tf"))) {
                        let val = stack.pop();
                        if (val === "t") {
                            seen_t = true;
                        }
                        if (val === "f") {
                            seen_f = true;
                        }
                    }
                    let op = stack.pop();
                    if (op === "!") {
                        stack.push((seen_t ? "f" : "t"));
                    } else {
                        if (op === "&") {
                            stack.push((seen_f ? "f" : "t"));
                        } else {
                            if (op === "|") {
                                stack.push((seen_t ? "t" : "f"));
                            }
                        }
                    }
                }
            }
        }
    }
    return stack[0] === "t";
}
function main() {
    let s = _stdin_all.trim();
    if (s) {
        console.log((parseBoolExpr(s) ? "true" : "false"));
    }
}
main();
