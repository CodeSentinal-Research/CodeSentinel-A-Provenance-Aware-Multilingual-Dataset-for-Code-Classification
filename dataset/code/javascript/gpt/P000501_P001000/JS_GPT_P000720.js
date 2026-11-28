// Expression Add Operators
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function add_ops(num, target, idx, cur_expr, cur_val, prev_op, res) {
    if (idx === (num.length !== undefined ? num.length : num.size)) {
        if (cur_val === target) {
            res.push(cur_expr);
        }
        return;
    }
    for (const i of Array.from({length: ((num.length !== undefined ? num.length : num.size)) - (idx)}, (_, i) => (idx) + i)) {
        if ((i > idx && num[idx] === "0")) {
            break;
        }
        let part = num.slice(idx, (i + 1));
        let v = parseInt(part, 10);
        if (idx === 0) {
            add_ops(num, target, (i + 1), part, v, v, res);
        } else {
            add_ops(num, target, (i + 1), ((cur_expr + "+") + part), (cur_val + v), v, res);
            add_ops(num, target, (i + 1), ((cur_expr + "-") + part), (cur_val - v), -(v), res);
            add_ops(num, target, (i + 1), ((cur_expr + "*") + part), ((cur_val - prev_op) + (prev_op * v)), (prev_op * v), res);
        }
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let num = tokens[0];
        let target = parseInt(tokens[1], 10);
        let res = [];
        add_ops(num, target, 0, "", 0, 0, res);
        for (const expr of [...res].sort((a, b) => a < b ? -1 : a > b ? 1 : 0)) {
            console.log(expr);
        }
    }
}
main();
