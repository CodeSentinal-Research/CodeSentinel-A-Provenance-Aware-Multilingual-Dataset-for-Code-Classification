// Maximum Average Subarray I
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
        let k = parseInt(tokens[(1 + n)], 10);
        let cur = nums.slice(0, k).reduce((a, b) => a + b, 0);
        let max_sum = cur;
        for (const i of Array.from({length: (n) - (k)}, (_, i) => (k) + i)) {
            cur += (nums[i] - nums[(i - k)]);
            max_sum = Math.max(max_sum, cur);
        }
        console.log(`${(max_sum / k)}`);
    }
}
main();
