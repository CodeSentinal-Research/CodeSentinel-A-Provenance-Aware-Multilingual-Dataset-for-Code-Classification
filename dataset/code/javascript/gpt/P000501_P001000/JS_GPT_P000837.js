// Minimize Maximum Distance to Gas Station
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    minmaxGasDist(stations, k) {
        function possible(d) {
            let count = 0;
            for (const i of Array.from({length: ((stations.length !== undefined ? stations.length : stations.size) - 1)}, (_, i) => i)) {
                count += parseInt(((stations[(i + 1)] - stations[i]) / d), 10);
            }
            return count <= k;
        }
        let [left, right] = [0.0, parseFloat((stations[-(1)] - stations[0]))];
        while ((right - left) > 1e-06) {
            let mid = ((left + right) / 2.0);
            if (possible(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
}
