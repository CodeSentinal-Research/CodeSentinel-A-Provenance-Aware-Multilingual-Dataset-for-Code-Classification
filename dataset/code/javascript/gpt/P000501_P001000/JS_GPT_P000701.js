// Find Minimum Element Using Recursion
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function min_rec(arr, idx) {
    if (idx === ((arr.length !== undefined ? arr.length : arr.size) - 1)) {
        return arr[idx];
    }
    return Math.min(arr[idx], min_rec(arr, (idx + 1)));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        console.log(min_rec(nums, 0));
    }
}
main();
