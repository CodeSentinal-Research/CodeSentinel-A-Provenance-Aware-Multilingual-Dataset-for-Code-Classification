// Count Inversions Using Recursive Merge Sort
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_inversions(arr) {
    function merge_sort(a) {
        if ((a.length !== undefined ? a.length : a.size) <= 1) {
            return [a, 0];
        }
        let mid = Math.floor((a.length !== undefined ? a.length : a.size) / 2);
        let [left, inv_l] = merge_sort(a.slice(0, mid));
        let [right, inv_r] = merge_sort(a.slice(mid));
        let merged = [];
        let i = 0;
        let j = 0;
        let inv = (inv_l + inv_r);
        while ((i < (left.length !== undefined ? left.length : left.size) && j < (right.length !== undefined ? right.length : right.size))) {
            if (left[i] <= right[j]) {
                merged.push(left[i]);
                i += 1;
            } else {
                merged.push(right[j]);
                inv += ((left.length !== undefined ? left.length : left.size) - i);
                j += 1;
            }
        }
        merged.push(...left.slice(i));
        merged.push(...right.slice(j));
        return [merged, inv];
    }
    let [_, total_inv] = merge_sort(arr);
    return total_inv;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        console.log(count_inversions(nums));
    }
}
main();
