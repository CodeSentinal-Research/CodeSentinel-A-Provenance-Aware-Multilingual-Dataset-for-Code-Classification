// Next Greater Element II
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let ans = ([-(1)] * n);
        let stack = [];
        for (const i of Array.from({length: (2 * n)}, (_, i) => i)) {
            let val = nums[(i % n)];
            while ((stack && nums[stack[-(1)]] < val)) {
                let prev = stack.pop();
                ans[prev] = val;
            }
            if (i < n) {
                stack.push(i);
            }
        }
        console.log(...ans);
    }
}
main();
