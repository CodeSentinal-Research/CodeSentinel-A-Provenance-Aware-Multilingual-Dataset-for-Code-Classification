// Pascal's Triangle Row
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class Solution {
    getRow(rowIndex) {
        let row = [1];
        for (const i of Array.from({length: rowIndex}, (_, i) => i)) {
            row = (([1] + [...Array.from({length: ((row.length !== undefined ? row.length : row.size) - 1)}, (_, i) => i)].map(j => (row[j] + row[(j + 1)]))) + [1]);
        }
        return row;
    }
}
