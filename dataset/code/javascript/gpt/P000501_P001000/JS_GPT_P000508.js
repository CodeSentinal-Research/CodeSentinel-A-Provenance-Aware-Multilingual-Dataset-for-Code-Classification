// Number of Visible People in a Queue
const fs = require("fs");
function _py_range(start, stop, step = 1) { const res = []; if (step > 0) { for (let i = start; i < stop; i += step) res.push(i); } else { for (let i = start; i > stop; i += step) res.push(i); } return res; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let heights = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let ans = ([0] * n);
        let stack = [];
        for (const i of _py_range((n - 1), -(1), -(1))) {
            let h = heights[i];
            let count = 0;
            while ((stack && stack[-(1)] < h)) {
                stack.pop();
                count += 1;
            }
            if (stack) {
                count += 1;
            }
            ans[i] = count;
            stack.push(h);
        }
        console.log(...ans);
    }
}
main();
