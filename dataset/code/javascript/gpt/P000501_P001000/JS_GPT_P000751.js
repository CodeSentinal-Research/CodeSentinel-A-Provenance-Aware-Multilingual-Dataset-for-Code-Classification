// Count All Subsequences with Given Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_subseq_sum(arr, idx, cur_sum, target) {
    if (idx === (arr.length !== undefined ? arr.length : arr.size)) {
        return (cur_sum === target ? 1 : 0);
    }
    return (count_subseq_sum(arr, (idx + 1), cur_sum, target) + count_subseq_sum(arr, (idx + 1), (cur_sum + arr[idx]), target));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let target = parseInt(tokens[(1 + n)], 10);
        console.log(count_subseq_sum(nums, 0, 0, target));
    }
}
main();
