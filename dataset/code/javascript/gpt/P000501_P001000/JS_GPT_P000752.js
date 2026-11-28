// Print Any One Subsequence with Given Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function find_one_subseq(arr, idx, cur, cur_sum, target) {
    if (idx === (arr.length !== undefined ? arr.length : arr.size)) {
        if ((cur_sum === target && cur)) {
            console.log(...cur);
            return true;
        }
        return false;
    }
    if (find_one_subseq(arr, (idx + 1), (cur + [arr[idx]]), (cur_sum + arr[idx]), target)) {
        return true;
    }
    if (find_one_subseq(arr, (idx + 1), cur, cur_sum, target)) {
        return true;
    }
    return false;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let target = parseInt(tokens[(1 + n)], 10);
        if (!(find_one_subseq(nums, 0, [], 0, target))) {
            console.log(-(1));
        }
    }
}
main();
