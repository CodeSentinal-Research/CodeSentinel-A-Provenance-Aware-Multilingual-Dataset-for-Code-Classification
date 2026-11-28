// Basic Calculator III
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function calculate(s) {
    function helper(it) {
        let stack = [];
        let num = 0;
        let sign = "+";
        while ((c = (it[0] !== undefined ? it[0] : null)) !== null) {
            if (/^\d+$/.test(c)) {
                num = ((num * 10) + parseInt(c, 10));
            } else {
                if (c === "(") {
                    num = helper(it);
                }
            }
            if ((_in(c, "+-*/)") || (next_char = (it[0] !== undefined ? it[0] : null)) === null)) {
                if ((c === null && next_char === null)) {
                    /* pass */
                }
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
                if (c === ")") {
                    break;
                }
                sign = c;
                num = 0;
            }
        }
        return stack.reduce((a, b) => a + b, 0);
    }
    function parse(s) {
        let st = [];
        let num = 0;
        let sign = "+";
        let i = 0;
        while (i < (s.length !== undefined ? s.length : s.size)) {
            let c = s[i];
            if (/^\d+$/.test(c)) {
                num = ((num * 10) + parseInt(c, 10));
            } else {
                if (c === "(") {
                    let [j, count] = [i, 0];
                    while (i < (s.length !== undefined ? s.length : s.size)) {
                        if (s[i] === "(") {
                            count += 1;
                        }
                        if (s[i] === ")") {
                            count -= 1;
                        }
                        if (count === 0) {
                            break;
                        }
                        i += 1;
                    }
                    num = parse(s.slice((j + 1), i));
                }
            }
            if ((_in(c, "+-*/") || i === ((s.length !== undefined ? s.length : s.size) - 1))) {
                if (sign === "+") {
                    st.push(num);
                } else {
                    if (sign === "-") {
                        st.push(-(num));
                    } else {
                        if (sign === "*") {
                            st.push((st.pop() * num));
                        } else {
                            if (sign === "/") {
                                st.push(parseInt((st.pop() / num), 10));
                            }
                        }
                    }
                }
                sign = c;
                num = 0;
            }
            i += 1;
        }
        return st.reduce((a, b) => a + b, 0);
    }
    return parse(s.replace(" ", ""));
}
function main() {
    let s = _stdin_all.trim();
    if (s) {
        console.log(calculate(s));
    }
}
main();
