// Recursive Heap Sort Verification
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_max_heap(arr, idx) {
    let n = (arr.length !== undefined ? arr.length : arr.size);
    let l = ((2 * idx) + 1);
    let r = ((2 * idx) + 2);
    if (l < n) {
        if ((arr[idx] < arr[l] || !(is_max_heap(arr, l)))) {
            return false;
        }
    }
    if (r < n) {
        if ((arr[idx] < arr[r] || !(is_max_heap(arr, r)))) {
            return false;
        }
    }
    return true;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        console.log((is_max_heap(nums, 0) ? "true" : "false"));
    }
}
main();
