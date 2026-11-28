// Painter's Partition Problem
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function painters_partition(arr, k) {
    function is_valid(max_len) {
        let painters = 1;
        let curr = 0;
        for (const x of arr) {
            if ((curr + x) > max_len) {
                painters += 1;
                curr = x;
            } else {
                curr += x;
            }
        }
        return painters <= k;
    }
    let [left, right] = [Math.max(...arr), arr.reduce((a, b) => a + b, 0)];
    let ans = right;
    while (left <= right) {
        let mid = (left + Math.floor((right - left) / 2));
        if (is_valid(mid)) {
            ans = mid;
            right = (mid - 1);
        } else {
            left = (mid + 1);
        }
    }
    return ans;
}
let [n, k] = _stdin_next_line().trim().split(/\s+/).map(Number);
let arr = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
console.log(painters_partition(arr, k));
