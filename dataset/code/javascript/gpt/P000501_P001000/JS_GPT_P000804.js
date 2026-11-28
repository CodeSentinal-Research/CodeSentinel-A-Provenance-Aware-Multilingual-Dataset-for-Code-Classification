// Count Subarrays with XOR Equal to K
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_subarrays_xor_k(arr, k) {
    let prefix_xor = 0;
    let count = 0;
    let freq = defaultdict(Number);
    freq[0] = 1;
    for (const num of arr) {
        prefix_xor ^= num;
        count += freq[(prefix_xor ^ k)];
        freq[prefix_xor] += 1;
    }
    return count;
}
let [n, k] = _stdin_next_line().trim().split(/\s+/).map(Number);
let arr = Array.from(_stdin_next_line().trim().split(/\s+/).map(Number));
console.log(count_subarrays_xor_k(arr, k));
