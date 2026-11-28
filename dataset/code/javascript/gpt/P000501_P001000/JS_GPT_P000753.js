// Print All Subsequences with Given Sum
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function find_all_subseq(arr, idx, cur, cur_sum, target, res) {
    if (idx === (arr.length !== undefined ? arr.length : arr.size)) {
        if ((cur_sum === target && cur)) {
            res.push(Array.from(cur));
        }
        return;
    }
    find_all_subseq(arr, (idx + 1), cur, cur_sum, target, res);
    find_all_subseq(arr, (idx + 1), (cur + [arr[idx]]), (cur_sum + arr[idx]), target, res);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let target = parseInt(tokens[(1 + n)], 10);
        let res = [];
        find_all_subseq(nums, 0, [], 0, target, res);
        res.sort();
        for (const seq of res) {
            console.log(...seq);
        }
    }
}
main();
