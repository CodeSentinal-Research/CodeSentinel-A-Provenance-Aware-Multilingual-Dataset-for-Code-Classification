// Minimum Number of Days to Make m Bouquets
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    minDays(bloomDay, m, k) {
        if ((m * k) > (bloomDay.length !== undefined ? bloomDay.length : bloomDay.size)) {
            return -(1);
        }
        function can_make(day) {
            let bouquets = 0;
            let flowers = 0;
            for (const b of bloomDay) {
                if (b <= day) {
                    flowers += 1;
                    if (flowers === k) {
                        bouquets += 1;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }
            return bouquets >= m;
        }
        let [left, right] = [Math.min(...bloomDay), Math.max(...bloomDay)];
        let ans = -(1);
        while (left <= right) {
            let mid = (left + Math.floor((right - left) / 2));
            if (can_make(mid)) {
                ans = mid;
                right = (mid - 1);
            } else {
                left = (mid + 1);
            }
        }
        return ans;
    }
}
