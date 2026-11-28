// Determine Triangle Type from Coordinates
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function triangle_type(x1, y1, x2, y2, x3, y3) {
    if ((((x1 * (y2 - y3)) + (x2 * (y3 - y1))) + (x3 * (y1 - y2))) === 0) {
        return "Not a Triangle";
    }
    let d1 = (Math.pow((x1 - x2), 2) + Math.pow((y1 - y2), 2));
    let d2 = (Math.pow((x2 - x3), 2) + Math.pow((y2 - y3), 2));
    let d3 = (Math.pow((x3 - x1), 2) + Math.pow((y3 - y1), 2));
    if (d1 === d2 && d2 === d3) {
        return "Equilateral";
    } else {
        if ((d1 === d2 || d2 === d3 || d3 === d1)) {
            return "Isosceles";
        } else {
            return "Scalene";
        }
    }
}
let [x1, y1, x2, y2, x3, y3] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(triangle_type(x1, y1, x2, y2, x3, y3));
