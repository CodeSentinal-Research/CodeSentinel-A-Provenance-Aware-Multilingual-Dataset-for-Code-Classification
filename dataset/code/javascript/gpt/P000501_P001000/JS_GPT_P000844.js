// Maximum Tastiness of Candy Basket
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    maximumTastiness(price, k) {
        price.sort();
        function can_pick(target) {
            let count = 1;
            let last = price[0];
            for (const i of Array.from({length: ((price.length !== undefined ? price.length : price.size)) - (1)}, (_, i) => (1) + i)) {
                if ((price[i] - last) >= target) {
                    count += 1;
                    last = price[i];
                    if (count === k) {
                        return true;
                    }
                }
            }
            return false;
        }
        let [left, right] = [0, (price[-(1)] - price[0])];
        let ans = 0;
        while (left <= right) {
            let mid = (left + Math.floor((right - left) / 2));
            if (can_pick(mid)) {
                ans = mid;
                left = (mid + 1);
            } else {
                right = (mid - 1);
            }
        }
        return ans;
    }
}
