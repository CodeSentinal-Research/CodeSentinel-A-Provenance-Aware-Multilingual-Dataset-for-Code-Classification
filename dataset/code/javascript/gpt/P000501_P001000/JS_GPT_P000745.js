// Recursive Insertion Sort
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function ins_sort_rec(arr, n) {
    if (n <= 1) {
        return;
    }
    ins_sort_rec(arr, (n - 1));
    let last = arr[(n - 1)];
    let j = (n - 2);
    while ((j >= 0 && arr[j] > last)) {
        arr[(j + 1)] = arr[j];
        j -= 1;
    }
    arr[(j + 1)] = last;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        ins_sort_rec(nums, n);
        console.log(...nums);
    }
}
main();
