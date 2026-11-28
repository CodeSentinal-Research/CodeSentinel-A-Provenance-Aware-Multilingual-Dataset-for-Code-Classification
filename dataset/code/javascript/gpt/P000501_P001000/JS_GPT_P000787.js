// Find the Middle Index in Array
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
        let left_sum = 0;
        let ans = -(1);
        for (const i of Array.from({length: n}, (_, i) => i)) {
            if (left_sum === ((total - left_sum) - nums[i])) {
                ans = i;
                break;
            }
            left_sum += nums[i];
        }
        console.log(ans);
    }
}
main();
