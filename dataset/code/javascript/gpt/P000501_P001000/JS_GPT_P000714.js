// Subset Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function subset_sum(arr, idx, cur_sum, res) {
    if (idx === (arr.length !== undefined ? arr.length : arr.size)) {
        res.push(cur_sum);
        return;
    }
    subset_sum(arr, (idx + 1), cur_sum, res);
    subset_sum(arr, (idx + 1), (cur_sum + arr[idx]), res);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let res = [];
        subset_sum(nums, 0, 0, res);
        console.log(...[...res].sort((a, b) => a < b ? -1 : a > b ? 1 : 0));
    }
}
main();
