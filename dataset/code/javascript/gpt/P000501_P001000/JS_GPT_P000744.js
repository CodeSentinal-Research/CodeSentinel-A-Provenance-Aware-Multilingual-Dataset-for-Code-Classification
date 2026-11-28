// Recursive Selection Sort
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function sel_sort_rec(arr, idx, n) {
    if (idx >= (n - 1)) {
        return;
    }
    let min_idx = idx;
    for (const i of Array.from({length: (n) - ((idx + 1))}, (_, i) => ((idx + 1)) + i)) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    [arr[idx], arr[min_idx]] = [arr[min_idx], arr[idx]];
    sel_sort_rec(arr, (idx + 1), n);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        sel_sort_rec(nums, 0, n);
        console.log(...nums);
    }
}
main();
