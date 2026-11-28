// Left and Right Sum Differences
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
        let total = nums.reduce((a, b) => a + b, 0);
        let left = 0;
        let ans = [];
        for (const x of nums) {
            let right = ((total - left) - x);
            ans.push(Math.abs((left - right)));
            left += x;
        }
        console.log(...ans);
    }
}
main();
