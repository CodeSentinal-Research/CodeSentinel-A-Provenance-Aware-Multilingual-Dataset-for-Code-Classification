// Heaters
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    findRadius(houses, heaters) {
        houses.sort();
        heaters.sort();
        let max_r = 0;
        for (const h of houses) {
            let idx = bisect.bisect_left(heaters, h);
            let dist = parseFloat("inf");
            if (idx < (heaters.length !== undefined ? heaters.length : heaters.size)) {
                dist = Math.min(dist, (heaters[idx] - h));
            }
            if (idx > 0) {
                dist = Math.min(dist, (h - heaters[(idx - 1)]));
            }
            max_r = Math.max(max_r, dist);
        }
        return max_r;
    }
}
