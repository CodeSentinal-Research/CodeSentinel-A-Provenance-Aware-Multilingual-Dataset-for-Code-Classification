// Count Diophantine Solutions in Range
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_diophantine_solutions(a, b, c, minx, maxx, miny, maxy) {
    function ext_gcd(a, b) {
        if (b === 0) {
            return [a, 1, 0];
        }
        let [g, x1, y1] = ext_gcd(b, (a % b));
        return [g, y1, (x1 - (Math.floor(a / b) * y1))];
    }
    let [g, x, y] = ext_gcd(Math.abs(a), Math.abs(b));
    if ((c % g) !== 0) {
        return 0;
    }
    x *= (Math.floor(c / g) * (a >= 0 ? 1 : -(1)));
    y *= (Math.floor(c / g) * (b >= 0 ? 1 : -(1)));
    let step_x = Math.floor(b / g);
    let step_y = Math.floor(a / g);
    function shift(x, y, a, b, cnt) {
        return [(x + (cnt * b)), (y - (cnt * a))];
    }
    let sign_x = (step_x > 0 ? 1 : -(1));
    let lx = (step_x > 0 ? Math.ceil(((minx - x) / step_x)) : Math.ceil(((maxx - x) / step_x)));
    let rx = (step_x > 0 ? Math.floor(((maxx - x) / step_x)) : Math.floor(((minx - x) / step_x)));
    let ly = (step_y > 0 ? Math.ceil(((y - maxy) / step_y)) : Math.ceil(((y - miny) / step_y)));
    let ry = (step_y > 0 ? Math.floor(((y - miny) / step_y)) : Math.floor(((y - maxy) / step_y)));
    let l = Math.max(lx, ly);
    let r = Math.min(rx, ry);
    return Math.max(0, ((r - l) + 1));
}
let [a, b, c] = _stdin_next_line().trim().split(/\s+/).map(Number);
let [minx, maxx, miny, maxy] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(count_diophantine_solutions(a, b, c, minx, maxx, miny, maxy));
