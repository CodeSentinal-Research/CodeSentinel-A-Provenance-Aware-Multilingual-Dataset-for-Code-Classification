// Maximum Width Ramp
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
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let stack = [];
        for (const i of Array.from({length: n}, (_, i) => i)) {
            if ((!(stack) || nums[stack[-(1)]] > nums[i])) {
                stack.push(i);
            }
        }
        let max_w = 0;
        for (const j of _py_range((n - 1), -(1), -(1))) {
            while ((stack && nums[stack[-(1)]] <= nums[j])) {
                max_w = Math.max(max_w, (j - stack.pop()));
            }
        }
        console.log(max_w);
    }
}
main();
