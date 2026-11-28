// Median of Two Sorted Arrays
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let [m, n] = _stdin_next_line().trim().split(/\s+/).map(Number);
let a = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let b = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
let c = [...(a + b)].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
let z = (c.length !== undefined ? c.length : c.size);
console.log(((z % 2) ? c[Math.floor(z / 2)] : ((c[(Math.floor(z / 2) - 1)] + c[Math.floor(z / 2)]) / 2)));
