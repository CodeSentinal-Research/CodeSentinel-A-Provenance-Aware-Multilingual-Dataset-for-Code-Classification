// Aggressive Cows
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function aggressive_cows(stalls, k) {
    stalls.sort();
    function can_place(min_dist) {
        let cows = 1;
        let last = stalls[0];
        for (const i of Array.from({length: ((stalls.length !== undefined ? stalls.length : stalls.size)) - (1)}, (_, i) => (1) + i)) {
            if ((stalls[i] - last) >= min_dist) {
                cows += 1;
                last = stalls[i];
                if (cows === k) {
                    return true;
                }
            }
        }
        return false;
    }
    let [left, right] = [1, (stalls[-(1)] - stalls[0])];
    let ans = 1;
    while (left <= right) {
        let mid = (left + Math.floor((right - left) / 2));
        if (can_place(mid)) {
            ans = mid;
            left = (mid + 1);
        } else {
            right = (mid - 1);
        }
    }
    return ans;
}
let [n, k] = _stdin_next_line().trim().split(/\s+/).map(Number);
let stalls = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
console.log(aggressive_cows(stalls, k));
