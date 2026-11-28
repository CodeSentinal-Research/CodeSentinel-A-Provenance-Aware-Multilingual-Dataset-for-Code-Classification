// Recursive Bubble Sort
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function bubble_sort_rec(arr, n) {
    if (n <= 1) {
        return;
    }
    for (const i of Array.from({length: (n - 1)}, (_, i) => i)) {
        if (arr[i] > arr[(i + 1)]) {
            [arr[i], arr[(i + 1)]] = [arr[(i + 1)], arr[i]];
        }
    }
    bubble_sort_rec(arr, (n - 1));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        bubble_sort_rec(nums, n);
        console.log(...nums);
    }
}
main();
