// Recursive Merge Sort
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function merge_sort(arr) {
    if ((arr.length !== undefined ? arr.length : arr.size) <= 1) {
        return arr;
    }
    let mid = Math.floor((arr.length !== undefined ? arr.length : arr.size) / 2);
    let left = merge_sort(arr.slice(0, mid));
    let right = merge_sort(arr.slice(mid));
    let res = [];
    let i = 0;
    let j = 0;
    while ((i < (left.length !== undefined ? left.length : left.size) && j < (right.length !== undefined ? right.length : right.size))) {
        if (left[i] <= right[j]) {
            res.push(left[i]);
            i += 1;
        } else {
            res.push(right[j]);
            j += 1;
        }
    }
    res.push(...left.slice(i));
    res.push(...right.slice(j));
    return res;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        console.log(...merge_sort(nums));
    }
}
main();
