// Check if Array is Palindrome Using Recursion
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function is_pal(arr, l, r) {
    if (l >= r) {
        return true;
    }
    if (arr[l] !== arr[r]) {
        return false;
    }
    return is_pal(arr, (l + 1), (r - 1));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = tokens.slice(1, (1 + n));
        console.log((is_pal(nums, 0, (n - 1)) ? "true" : "false"));
    }
}
main();
