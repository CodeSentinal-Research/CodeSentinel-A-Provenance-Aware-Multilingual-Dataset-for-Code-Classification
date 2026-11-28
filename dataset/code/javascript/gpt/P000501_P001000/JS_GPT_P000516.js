// Shortest Unsorted Continuous Subarray
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
        let sorted_nums = [...nums].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        let [l, r] = [0, (n - 1)];
        while ((l < n && nums[l] === sorted_nums[l])) {
            l += 1;
        }
        while ((r > l && nums[r] === sorted_nums[r])) {
            r -= 1;
        }
        console.log((r >= l ? ((r - l) + 1) : 0));
    }
}
main();
