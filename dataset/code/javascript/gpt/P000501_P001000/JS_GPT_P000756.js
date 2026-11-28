// Recursive Quick Sort
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function quick_sort(arr, l, r) {
    if (l >= r) {
        return;
    }
    let pivot = arr[r];
    let p_idx = l;
    for (const i of Array.from({length: (r) - (l)}, (_, i) => (l) + i)) {
        if (arr[i] < pivot) {
            [arr[i], arr[p_idx]] = [arr[p_idx], arr[i]];
            p_idx += 1;
        }
    }
    [arr[p_idx], arr[r]] = [arr[r], arr[p_idx]];
    quick_sort(arr, l, (p_idx - 1));
    quick_sort(arr, (p_idx + 1), r);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        quick_sort(nums, 0, (n - 1));
        console.log(...nums);
    }
}
main();
