// Number of Submatrices That Sum to Target
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    numSubmatrixSumTarget(matrix, target) {
        let [r, c] = [(matrix.length !== undefined ? matrix.length : matrix.size), (matrix[0].length !== undefined ? matrix[0].length : matrix[0].size)];
        for (const row of matrix) {
            for (const j of Array.from({length: (c) - (1)}, (_, i) => (1) + i)) {
                row[j] += row[(j - 1)];
            }
        }
        let count = 0;
        for (const c1 of Array.from({length: c}, (_, i) => i)) {
            for (const c2 of Array.from({length: (c) - (c1)}, (_, i) => (c1) + i)) {
                let sum_map = defaultdict(Number);
                sum_map[0] = 1;
                let curr_sum = 0;
                for (const row of Array.from({length: r}, (_, i) => i)) {
                    curr_sum += (matrix[row][c2] - (c1 > 0 ? matrix[row][(c1 - 1)] : 0));
                    count += sum_map[(curr_sum - target)];
                    sum_map[curr_sum] += 1;
                }
            }
        }
        return count;
    }
}
