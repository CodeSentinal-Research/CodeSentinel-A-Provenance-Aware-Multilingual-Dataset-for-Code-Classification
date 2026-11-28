// Search a 2D Matrix
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    searchMatrix(matrix, target) {
        if ((!(matrix) || !(matrix[0]))) {
            return false;
        }
        let [m, n] = [(matrix.length !== undefined ? matrix.length : matrix.size), (matrix[0].length !== undefined ? matrix[0].length : matrix[0].size)];
        let [left, right] = [0, ((m * n) - 1)];
        while (left <= right) {
            let mid = (left + Math.floor((right - left) / 2));
            let val = matrix[Math.floor(mid / n)][(mid % n)];
            if (val === target) {
                return true;
            } else {
                if (val < target) {
                    left = (mid + 1);
                } else {
                    right = (mid - 1);
                }
            }
        }
        return false;
    }
}
